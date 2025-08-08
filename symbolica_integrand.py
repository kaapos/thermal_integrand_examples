import numpy as np
import os
import json
from time import perf_counter
from integrand import Integrand, IntegrandResult
from symbolica import *
import gc

# Suppress warnings about small numbers
import warnings
warnings.filterwarnings('ignore', message='.*smallest.*subnormal.*')

class SymbolicaIntegrand(Integrand):
    """Evaluates the integrand for given momenta and jacobian.
    
    This class provides an interface to evaluate the Symbolica integrand implementation
    for a set of input momenta and jacobian values.
    
    Attributes:
        n_edges: Number of edges in the diagram
        n_loops: Number of loops in the diagram
        dim: Dimension of the momentum space
        n_params: Number of physical parameters
        params: Array of physical parameters
        timing_us_per_point: Last evaluation timing in microseconds per point
        path_to_example: Path to the example directory containing src
    """
    
    def __init__(self, params: np.ndarray, path_to_example: str, force_rebuild: bool = False, do_stability_check: bool = False, stability_tolerance: float = 1e-3, stability_abs_threshold: float = 1e-12, rotation_seed: int = None, n_shots: int = 3):
        """Initialize the integrand.
        
        Args:
            params: Array of physical parameters
            path_to_example: Path to the example directory containing src (e.g., 'examples/sunset2')
            force_rebuild: Force rebuilding the C extension even if it exists
            do_stability_check: Whether to perform numerical stability checks
            stability_tolerance: Threshold for the stability check
            stability_abs_threshold: Threshold for the switch between absolute and relative stability check
            rotation_seed: Seed for the random rotation matrix
            n_shots: Number of evaluations in stability check (original + n_shots-1 rotations)
        """
        super().__init__(params, path_to_example)
        self.force_rebuild = bool(force_rebuild)
        self.do_stability_check = bool(do_stability_check)
        self.stability_tolerance = float(stability_tolerance)
        self.stability_abs_threshold = float(stability_abs_threshold)
        self.rotation_seed = rotation_seed
        self.n_shots = int(n_shots)
        # Construct path to the config file
        config_path = os.path.join(self.path_to_example, "src", "symbolica_integrand", "config.json")
        # Load variables from config.json
        with open(config_path, "r") as f:
            config = json.load(f)
        self.n_edges = config["n_edges"]
        self.n_loops = config["n_loops"]
        self.n_sps = config["n_sps"]
        self.dim = config["dim"]
        self.n_vars = self.dim * self.n_loops + self.n_params

        self.compiled_evaluator = None
        self._rotation_seeded = False

    def __getstate__(self):
        state = self.__dict__.copy()
        # Always exclude these objects as they can't be pickled
        state['compiled_evaluator'] = None
        return state

    def __setstate__(self, state):
        self.__dict__.update(state)
        self.compiled_evaluator = None
        # Ensure _rotation_seeded is initialized if not present (for backward compatibility)
        if not hasattr(self, '_rotation_seeded'):
            self._rotation_seeded = False
        # Don't immediately setup - let it be lazy loaded when needed

    def _setup_symbolica_integrand(self):
        # Check if we can reuse existing compiled evaluator
        if (self.compiled_evaluator is not None):
            return  # Already compiled

        build_dir = os.path.join(self.path_to_example, "build", "symbolica_integrand")
        os.makedirs(build_dir, exist_ok=True)
        
        # Use example name for shared filenames
        example_name = os.path.basename(os.path.normpath(self.path_to_example))
        cpp_path = os.path.join(build_dir, f"integrand_{example_name}.cpp")
        so_path = os.path.join(build_dir, f"integrand_{example_name}.so")
        
        # Helper function to compile evaluator (expensive operation)
        def compile_evaluator():
            print(f"Compiling evaluator for {example_name}")
            
            ose, sp, m = S("ose", "sp", "m")

            # Load dot products from JSON file
            with open(os.path.join(self.path_to_example, "src", "symbolica_integrand", "dotproducts.json"), "r") as f:
                dot_products = json.load(f)
            
            # Create sp variables dynamically based on dot_products
            sp_expressions = {}
            for sp_name, expression_str in dot_products.items():
                sp_expressions[sp_name] = E(expression_str)

            integrand = E(open(os.path.join(self.path_to_example, "src", "symbolica_integrand", "integrand.txt")).read())
            with open(os.path.join(self.path_to_example, "src", "symbolica_integrand", "variables.json"), "r") as f:
                vars = json.load(f)

            # Replace sp variables in integrand dynamically
            for sp_name, sp_expression in sp_expressions.items():
                integrand = integrand.replace(S(sp_name), sp_expression)
            
            external_functions = {
                (S("Tanh"), "tanh"): lambda args: np.tanh(args[0]),
                (S("Coth"), "coth"): lambda args: 1/(np.tanh(args[0])),
                (S("Sech"), "sech"): lambda args: 1/(np.cosh(args[0])),
                (S("Csch"), "csch"): lambda args: 1/(np.sinh(args[0]))
            }

            evaluator = integrand.evaluator({}, {(ose, "ose", (sp, m)): E("(sp+m^2)^0.5"), }, [S(x) for x in vars], iterations=0, external_functions=external_functions)

            custom_header = (
                "template<typename T> T tanh(T x) { return std::tanh(x); } "
                "template<typename T> T coth(T x) { return T(1)/std::tanh(x); } "
                "template<typename T> T sech(T x) { return T(1)/std::cosh(x); } "
                "template<typename T> T csch(T x) { return T(1)/std::sinh(x); }"
            )

            evaluator.compile('integrand', cpp_path, so_path, 'real', inline_asm='default', custom_header=custom_header)
            del evaluator
            gc.collect()
        
        if self.force_rebuild or not (os.path.exists(so_path) and os.path.getsize(so_path) > 0):
            compile_evaluator()
            self.force_rebuild = False
        
        self.compiled_evaluator = CompiledRealEvaluator.load(so_path, 'integrand', self.n_vars , 1)

    def _ensure_compiled_evaluator(self):
        if self.compiled_evaluator is None:
            self._setup_symbolica_integrand()
    
    def set_params(self, params: np.ndarray = None):
        if params is not None:
            params = np.asarray(params, dtype=np.float64)
            if len(params) != self.n_params:
                raise ValueError(f"params must be an array of length {self.n_params}")
            self.params = params
    
    def _generate_rotation_matrix(self, dim):
        """Generate a random rotation matrix of given dimension.
        
        Uses QR decomposition to create a proper orthogonal matrix with determinant +1.
        Seeds the random generator on first call if rotation_seed is provided, then
        preserves the generator state for subsequent calls.
        
        Args:
            dim: Dimension of the rotation matrix
            
        Returns:
            numpy.ndarray: Random rotation matrix of shape (dim, dim)
        """
        
        # Set seed only on first call if rotation_seed is provided
        if not self._rotation_seeded and self.rotation_seed is not None:
            np.random.seed(self.rotation_seed)
            self._rotation_seeded = True
        
        # Generate a random matrix
        random_matrix = np.random.randn(dim, dim)
        # Use QR decomposition to get an orthogonal matrix
        Q, R = np.linalg.qr(random_matrix)
        # Ensure proper rotation (det = 1) rather than reflection (det = -1)
        if np.linalg.det(Q) < 0:
            Q[:, 0] *= -1
        return Q
    
    def _randomly_rotate_loop_momenta(self, loop_momentum_array: np.ndarray) -> np.ndarray:
        """
        Rotate all loop momenta in the array using a random rotation matrix.

        Args:
            loop_momentum_array: np.ndarray of shape (n_points, n_loops, dim)
            seed: Optional random seed for reproducibility

        Returns:
            np.ndarray: Rotated loop momentum array of the same shape.
        """
        n_points, n_loops, dim = loop_momentum_array.shape
        rotation_matrix = self._generate_rotation_matrix(dim)
        # Apply the rotation to each momentum vector
        # Shape: (n_points, n_loops, dim) x (dim, dim) -> (n_points, n_loops, dim)
        rotated = np.einsum('ij,...j->...i', rotation_matrix, loop_momentum_array)
        return rotated

    
    def _rotate_loop_momenta_around_axis(self, loop_momentum_array: np.ndarray, axis: int) -> np.ndarray:
        """
        Rotate all loop momenta in the array around the specified axis by pi/2.

        Args:
            loop_momentum_array: np.ndarray of shape (n_points, n_loops, dim)
            axis: int, the axis (0-based) around which to rotate (0 <= axis < dim)

        Returns:
            np.ndarray: Rotated loop momentum array of the same shape.
        """
        n_points, n_loops, dim = loop_momentum_array.shape
        if not (0 <= axis < dim):
            raise ValueError(f"axis must be in [0, {dim-1}]")
        # Create identity rotation matrix
        rotation_matrix = np.eye(dim)
        # Find two axes to rotate in (perpendicular to 'axis')
        axes = [i for i in range(dim) if i != axis]
        if len(axes) < 2:
            # If dim == 1, nothing to rotate
            return loop_momentum_array.copy()
        # For simplicity, rotate in the plane of the first two axes perpendicular to 'axis'
        i, j = axes[0], axes[1]
        # pi/2 rotation in (i, j) plane
        rotation_matrix[i, i] = 0
        rotation_matrix[j, j] = 0
        rotation_matrix[i, j] = -1
        rotation_matrix[j, i] = 1
        # Apply rotation to each momentum vector
        # Shape: (n_points, n_loops, dim) x (dim, dim) -> (n_points, n_loops, dim)
        rotated = np.einsum('ij,...j->...i', rotation_matrix, loop_momentum_array)
        return rotated
    
    def evaluate(self, jacobian_array: np.ndarray, loop_momentum_array: np.ndarray) -> IntegrandResult:
        self._ensure_compiled_evaluator()
        start_time = perf_counter()
        n_points = len(jacobian_array)
        expected_momentum_shape = (n_points, self.n_loops, self.dim)
        if loop_momentum_array.shape != expected_momentum_shape:
            raise ValueError(
                f"loop_momentum_array shape {loop_momentum_array.shape} does not match "
                f"expected shape {expected_momentum_shape}"
            )
        
        # Helper function to evaluate with given momentum array
        def _evaluate_with_momentum(momentum_array):
            # Reshape momentum array from (n_points, n_loops, dim) to (n_points, n_loops*dim)
            momentum_flat = momentum_array.reshape(n_points, self.n_loops * self.dim)
            
            # Concatenate flattened momentum with parameters to get shape (n_points, n_loops*dim + n_params)
            variables = np.hstack([momentum_flat, np.tile(self.params, (n_points, 1))])

            # Evaluate using compiled evaluator and handle NaN values
            evaluated_result = np.asarray(self.compiled_evaluator.evaluate(variables)).ravel()
            return jacobian_array * evaluated_result
        
        # First evaluate with original loop momenta
        result = _evaluate_with_momentum(loop_momentum_array)
        
        if self.do_stability_check and self.n_shots > 1:
            # Collect all results: original + rotations around random axes
            all_results = [result]  # Start with original result
            
            # Compute rotations around random axes
            for _ in range(self.n_shots - 1):
                rotated_loop_momentum_array = self._randomly_rotate_loop_momenta(loop_momentum_array)
                result_rotated = _evaluate_with_momentum(rotated_loop_momentum_array)
                all_results.append(result_rotated)
            
            # Stack all results and compute average
            all_results_array = np.stack(all_results, axis=0)  # Shape: (n_shots, n_points)
            average_result = np.mean(all_results_array, axis=0)  # Shape: (n_points,)

            # # Collect all results: original + rotations around each axis
            # all_results = [result]  # Start with original result
            
            # # Compute rotations around each axis
            # for axis in range(self.dim):
            #     rotated_loop_momentum_array = self._rotate_loop_momenta_around_axis(loop_momentum_array, axis)
            #     result_rotated = _evaluate_with_momentum(rotated_loop_momentum_array)
            #     all_results.append(result_rotated)
            
            # # Stack all results and compute average
            # all_results_array = np.stack(all_results, axis=0)  # Shape: (dim+1, n_points)
            # average_result = np.mean(all_results_array, axis=0)  # Shape: (n_points,)
            
            # # Rotate around x-axis
            # rotated_loop_momentum_array = self._rotate_loop_momenta_around_axis(loop_momentum_array, axis=0)
            # result_rotated = _evaluate_with_momentum(rotated_loop_momentum_array)
            # all_results = [result, result_rotated]
            # all_results_array = np.stack(all_results, axis=0)  # Shape: (dim+1, n_points)
            # average_result = np.mean(all_results_array, axis=0)  # Shape: (n_points,)

            # Check stability by comparing each result against the average
            epsilon = 1e-20  # Small value to avoid division by zero
            stability_mask = np.zeros(n_points, dtype=bool)
            
            for single_result in all_results:
                # Calculate absolute difference from average
                abs_diff = np.abs(single_result - average_result)
                
                # Calculate magnitude for relative error computation
                max_magnitude = np.maximum(np.abs(average_result), epsilon)
                
                # Calculate relative difference
                rel_diff = abs_diff / max_magnitude
                
                # Use mixed criterion: absolute for small values, relative for large values
                result_difference = np.where(
                    max_magnitude < self.stability_abs_threshold,
                    abs_diff,  # Use absolute difference for small values
                    rel_diff   # Use relative difference for large values
                )
                
                # Mark points as unstable if any result differs from average by more than tolerance
                stability_mask |= (result_difference > self.stability_tolerance)
            
            # Replace original result with NaN where any rotation differs from average
            result[stability_mask] = np.nan
        
        # Create success array based on both evaluations
        success = np.ones(n_points, dtype=np.int32)
        # Find NaN values in either result and replace difference with 0.0, mark as failed in success
        nan_mask = np.isnan(result)
        result[nan_mask] = 0.0
        success[nan_mask] = 0

        end_time = perf_counter()
        self.timing_us_per_point = 1e6 * (end_time - start_time) / n_points
        return IntegrandResult(
            values=result,
            success=success,
            timing_us_per_point=self.timing_us_per_point
        )
