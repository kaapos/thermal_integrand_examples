import numpy as np
import os
import json
from time import perf_counter
from .integrand import Integrand, IntegrandResult
from symbolica import *
import gc
from samplers.sampler import SamplerResult, OrientedSamplerResult
import itertools

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
        n_sps: Number of dot products in the diagram
        dim: Dimension of the momentum space
        edge_tags: List of edge tags in the diagram
        n_vars: Number of variables in the integrand
        n_params: Number of physical parameters
        params: Array of physical parameters
        timing_us_per_point: Last evaluation timing in microseconds per point
        path_to_example: Path to the example directory containing src
    """
    
    def __init__(
        self,
        params: np.ndarray,
        path_to_example: str,
        force_rebuild: bool = False,
        stability_tolerance: float = 1e-3,
        stability_abs_tolerance: float = 1e-15,
        stability_abs_threshold: float = 1e-12,
        escalate_large_weight_multiplier: float = -1.0,
        escalate_small_momentum_multiplier: float = -1.0,
        escalate_large_momentum_multiplier: float = -1.0,
        rotation_seed: int = None,
        n_shots: int = 3,
        build_eagerly: bool = True,
        sum_orientations: bool = True,
        runtime_summation: bool = False
    ):
        """Initialize the integrand.
        
        Args:
            params: Array of physical parameters
            path_to_example: Path to the example directory containing src (e.g., 'examples/sunset2')
            force_rebuild: Force rebuilding the C extension even if it exists
            stability_tolerance: Threshold for the relative stability check
            stability_abs_tolerance: Threshold for the absolute stability check
            stability_abs_threshold: Threshold for the switch between absolute and relative stability check
            escalate_large_weight_multiplier: Escalate to high precision if the weight is larger than this multiplier times the maximum weight. If negative, do not escalate.
            escalate_small_momentum_multiplier: Escalate to high precision if any of the loop momenta is smaller than this multiplier times the unit energy. If negative, do not escalate.
            escalate_large_momentum_multiplier: Escalate to high precision if any of the loop momenta is larger than this multiplier times the unit energy. If negative, do not escalate.
            rotation_seed: Seed for the random rotation matrix
            n_shots: Number of evaluations in stability check (original + n_shots-1 rotations)
            build_eagerly: Whether to build the evaluator eagerly
            sum_orientations: Whether to sum over all orientations
            runtime_summation: If True and sum_orientations=True, sum orientations at runtime instead of pre-compiling them. Reduces memory but increases evaluation time.
        """
        super().__init__(params, path_to_example)
        self.force_rebuild = bool(force_rebuild)
        self.stability_tolerance = float(stability_tolerance)
        self.stability_abs_tolerance = float(stability_abs_tolerance)
        self.stability_abs_threshold = float(stability_abs_threshold)
        self.escalate_large_weight_multiplier = float(escalate_large_weight_multiplier)
        self.escalate_small_momentum_multiplier = float(escalate_small_momentum_multiplier)
        self.escalate_large_momentum_multiplier = float(escalate_large_momentum_multiplier)
        self.max_weight = 0.0
        self.rotation_seed = rotation_seed
        self.n_shots = int(n_shots)
        self.sum_orientations = bool(sum_orientations)
        self.runtime_summation = bool(runtime_summation)
        if self.runtime_summation and not self.sum_orientations:
            raise ValueError("runtime_summation can only be True when sum_orientations is True")
        # Construct path to the config file
        config_path = os.path.join(self.path_to_example, "src", "symbolica_integrand", "config.json")
        # Load variables from config.json
        with open(config_path, "r") as f:
            self.config = json.load(f)
        self.n_edges = self.config["n_edges"]
        self.n_loops = self.config["n_loops"]
        self.n_sps = self.config["n_sps"]
        self.dim = self.config["dim"]
        self.edge_tags = self.config["edge_tags"]
        if self.sum_orientations and not self.runtime_summation:
            self.n_vars = self.dim * self.n_loops + self.n_params
        else:
            # Both sum_orientations=False and runtime_summation=True cases need orientation variables
            self.n_vars = self.dim * self.n_loops + self.n_params + self.n_edges

        self.compiled_evaluator = None
        if build_eagerly:
            self._ensure_evaluator()
        # Per-instance RNG to avoid global-state coupling when multiple Integrands share a process
        # Deterministic across runs when rotation_seed is provided
        self._rng = np.random.default_rng(rotation_seed) if rotation_seed is not None else None

    def __getstate__(self):
        state = self.__dict__.copy()
        # Always exclude these objects as they can't be pickled or should be reconstructed
        state['compiled_evaluator'] = None
        # Reconstruct RNG from seed on restore to guarantee determinism and avoid cross-process issues
        state['_rng'] = None
        return state

    def __setstate__(self, state):
        self.__dict__.update(state)
        self.compiled_evaluator = None
        # RNG will be lazily reconstructed on first rotation use
        if not hasattr(self, '_rng'):
            self._rng = None

    def _ensure_evaluator(self):
        """Prepare the evaluator - to be implemented by subclasses."""
        # Check if we can reuse existing compiled evaluator
        if (self.compiled_evaluator is not None):
            return  # Already compiled

        build_dir = os.path.join(self.path_to_example, "build", "symbolica_integrand")
        os.makedirs(build_dir, exist_ok=True)
        
        # Use example name for shared filenames
        example_name = os.path.basename(os.path.normpath(self.path_to_example))
        if self.sum_orientations and not self.runtime_summation:
            cpp_path = os.path.join(build_dir, f"integrand_{example_name}.cpp")
            so_path = os.path.join(build_dir, f"integrand_{example_name}.so")
        else:
            # Both sum_orientations=False and runtime_summation=True use the same evaluator type
            cpp_path = os.path.join(build_dir, f"integrand_{example_name}_rho_term.cpp")
            so_path = os.path.join(build_dir, f"integrand_{example_name}_rho_term.so")
        
        # Helper function to compile evaluator (expensive operation)
        def compile_evaluator():
            print(f"Compiling evaluator for {example_name}")

            loop_momentum_vars = [S(x) for x in self.config["loop_momentum_components"]]
            if self.sum_orientations and not self.runtime_summation:
                sign_vars = []
            else:
                sign_vars = [S(f"rho_{tag}") for tag in self.edge_tags]
            param_vars = [S(x) for x in self.config["parameters"]]
            vars_list = loop_momentum_vars + sign_vars + param_vars

            functions = {}
            functions[(S("ose"), "ose", (S("sp"), S("m")))] = E("(sp+m^2)^0.5")

            dot_products = self.config["dot_products"]

            for sp_name, expression_str in dot_products.items():
                functions[(S(sp_name), sp_name, tuple(loop_momentum_vars))] = E(expression_str)

            # Read integrand as Symbolica expression
            integrand_expr = E(open(os.path.join(self.path_to_example, "src", "symbolica_integrand", "integrand.txt")).read())

            if self.sum_orientations and not self.runtime_summation:
                # Pre-compile sum over all orientations
                sum_expr = E("0")
                for signs in itertools.product([-1, 1], repeat=len(self.edge_tags)):
                    term = integrand_expr
                    for tag, sign in zip(self.edge_tags, signs):
                        pattern = E(f"rho('{tag}')")
                        term = term.replace(pattern, sign)
                    sum_expr = sum_expr + term

                integrand = sum_expr
            else:
                # Keep rho variables for runtime evaluation (both sum_orientations=False and runtime_summation=True)
                integrand = integrand_expr
                for tag in self.edge_tags:
                    integrand = integrand.replace(E(f"rho('{tag}')"), S(f"rho_{tag}"))

            # Replace sp variables with sp functions in integrand dynamically
            for sp_name, _ in dot_products.items():
                integrand = integrand.replace(S(sp_name), S(sp_name)(*loop_momentum_vars))
            
            external_functions = {
                (S("Tanh"), "tanh"): lambda args: np.tanh(args[0]),
                (S("Coth"), "coth"): lambda args: 1/(np.tanh(args[0])),
                (S("Sech"), "sech"): lambda args: 1/(np.cosh(args[0])),
                (S("Csch"), "csch"): lambda args: 1/(np.sinh(args[0]))
            }

            evaluator = integrand.evaluator({}, functions, vars_list, iterations=0, external_functions=external_functions)

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
        
        # Use a per-instance RNG for determinism and to avoid affecting global RNG state
        if self._rng is None:
            # Lazily create RNG so that objects unpickled without _rng still work deterministically
            self._rng = np.random.default_rng(self.rotation_seed) if self.rotation_seed is not None else np.random.default_rng()

        # Generate a random matrix
        random_matrix = self._rng.standard_normal((dim, dim))
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
    
    def _rotation_stability_mask(self, base_result: np.ndarray, loop_momentum_array: np.ndarray, weight_array: np.ndarray, evaluate_with_momentum):
        """
        Compute a boolean mask marking unstable points under random rotations.

        Args:
            base_result: 1D array of results for the original loop momenta (n_points,)
            loop_momentum_array: Array of loop momenta (n_points, n_loops, dim)
            weight_array: Array of weights (n_points,)
            evaluate_with_momentum: Callable that maps a momentum array of shape
                (n_points, n_loops, dim) -> evaluated values (n_points,)

        Returns:
            np.ndarray: Boolean mask of shape (n_points,) where True indicates instability.
        """

        n_points = base_result.shape[0]
        epsilon = 1e-20  # Small value to avoid division by zero
        stability_mask = np.zeros(n_points, dtype=bool)

        loop_momentum_norm = np.linalg.norm(loop_momentum_array, axis=2)

        # Mark points as unstable if any of the loop momenta is smaller than the escalate_small_momentum_multiplier
        if self.escalate_small_momentum_multiplier > 0.0:
            stability_mask |= np.any(loop_momentum_norm < self.escalate_small_momentum_multiplier, axis=1)

        # Mark points as unstable if any of the loop momenta is larger than the escalate_large_momentum_multiplier
        if self.escalate_large_momentum_multiplier > 0.0:
            stability_mask |= np.any(loop_momentum_norm > self.escalate_large_momentum_multiplier, axis=1)

        all_results_array = np.empty((self.n_shots, n_points))

        # Collect all results: original + rotations around random axes
        all_results_array[0] = base_result

        for i in range(1, self.n_shots):
            rotated_loop_momentum_array = self._randomly_rotate_loop_momenta(loop_momentum_array)
            all_results_array[i] = evaluate_with_momentum(rotated_loop_momentum_array)

        # Compute average
        average_result = np.mean(all_results_array, axis=0)  # Shape: (n_points,)

        # Check stability by comparing each result against the average
        for i in range(self.n_shots):
            single_result = all_results_array[i]

            # Calculate absolute difference from average
            abs_diff = np.abs(single_result - average_result)

            # Calculate magnitude for relative error computation
            magnitude = np.maximum(np.abs(average_result), epsilon)

            # Calculate relative difference
            rel_diff = abs_diff / magnitude

            # Use mixed criterion: absolute for small values, relative for large values
            result_difference = np.where(
                magnitude < self.stability_abs_threshold,
                abs_diff,  # Use absolute difference for small values
                rel_diff   # Use relative difference for large values
            )
            
            # Use appropriate tolerance based on whether we're using absolute or relative differences
            tolerance_to_use = np.where(
                magnitude < self.stability_abs_threshold,
                self.stability_abs_tolerance,  # Use absolute tolerance for small values
                self.stability_tolerance       # Use relative tolerance for large values
            )

            # Mark points as unstable if any result differs from average by more than tolerance
            stability_mask |= (result_difference > tolerance_to_use)

        # Mark points as unstable if the weight is larger than the maximum weight times the escalate_large_weight_multiplier
        magnitude_array = weight_array * np.abs(average_result)
        if self.escalate_large_weight_multiplier > 0.0 and self.max_weight > 0.0:
            for i in range(len(magnitude_array)):
                if magnitude_array[i] > self.escalate_large_weight_multiplier * self.max_weight:
                    stability_mask[i] = True
                elif not stability_mask[i]:
                    self.max_weight = max(self.max_weight, magnitude_array[i])
        else:
            self.max_weight = max(self.max_weight, np.max(magnitude_array))

        # If averaging produced NaNs (e.g., some evaluation failed), mark those as unstable
        stability_mask |= np.isnan(average_result)

        return stability_mask

    def _validate_sampler_result(self, sampler_result: SamplerResult, n_points: int):
        """Validate the sampler result inputs."""
        expected_momentum_shape = (n_points, self.n_loops, self.dim)
        if sampler_result.loop_momentum_array.shape != expected_momentum_shape:
            raise ValueError(
                f"loop_momentum_array shape {sampler_result.loop_momentum_array.shape} does not match "
                f"expected shape {expected_momentum_shape}"
            )
        if not self.sum_orientations:
            if not isinstance(sampler_result, OrientedSamplerResult):
                raise ValueError(
                    f"sampler_result must be an OrientedSamplerResult when sum_orientations is False"
                )
            if sampler_result.orientation_vector_array.shape != (n_points, self.n_edges):
                raise ValueError(
                    f"orientation_array shape {sampler_result.orientation_vector_array.shape} does not match "
                    f"expected shape {n_points, self.n_edges}"
                )
    
    def _evaluate_variables(self, variables: np.ndarray) -> np.ndarray:
        """Evaluate the integrand for the given variables - to be implemented by subclasses."""
        values = self.compiled_evaluator.evaluate(variables)
        return np.asarray(values).ravel()

    def evaluate(self, sampler_result: SamplerResult, max_weight: float = 0.0) -> IntegrandResult:
        """Template method for evaluation - delegates specific evaluation to subclasses."""
        self._ensure_evaluator()
        start_time = perf_counter()
        n_points = len(sampler_result.jacobian_array)

        self.max_weight = max(self.max_weight, max_weight)
        
        # Validate inputs
        self._validate_sampler_result(sampler_result, n_points)
        
        # Helper function to evaluate with given momentum array and optional orientation
        def _evaluate_with_momentum(momentum_array: np.ndarray, orientation_signs: np.ndarray = None) -> np.ndarray:
            # Reshape momentum array from (n_points, n_loops, dim) to (n_points, n_loops*dim)
            momentum_flat = momentum_array.reshape(n_points, self.n_loops * self.dim)
            # Concatenate flattened momentum with parameters to get shape (n_points, n_loops*dim + n_params)
            if self.sum_orientations and not self.runtime_summation:
                # Pre-computed sum: no orientation variables needed
                variables = np.hstack([momentum_flat, np.tile(self.params, (n_points, 1))])
            else:
                # Need orientation variables (either sum_orientations=False or runtime_summation=True)
                if orientation_signs is None:
                    if isinstance(sampler_result, OrientedSamplerResult):
                        orientation_signs = sampler_result.orientation_vector_array
                    else:
                        raise ValueError("orientation_signs required when sum_orientations=False or for runtime summation")
                variables = np.hstack([momentum_flat, orientation_signs, np.tile(self.params, (n_points, 1))])
            
            # Delegate to subclass-specific evaluation
            values = self._evaluate_variables(variables)
            return sampler_result.jacobian_array * values
        
        # Handle different evaluation modes
        if self.sum_orientations and self.runtime_summation:
            # Runtime summation: evaluate for each orientation combination and sum
            result = np.zeros(n_points)
            orientation_combinations = list(itertools.product([-1, 1], repeat=len(self.edge_tags)))
            
            for signs in orientation_combinations:
                # Create orientation array for this combination
                orientation_array = np.tile(np.array(signs), (n_points, 1))
                term_result = _evaluate_with_momentum(sampler_result.loop_momentum_array, orientation_array)
                result += term_result
        else:
            # Standard evaluation (either pre-computed sum or single orientation)
            result = _evaluate_with_momentum(sampler_result.loop_momentum_array)
        
        # Stability check wrapper for runtime summation
        if self.sum_orientations and self.runtime_summation:
            # For stability check, we need a version of _evaluate_with_momentum that handles the summation
            def _evaluate_with_momentum_summed(momentum_array: np.ndarray) -> np.ndarray:
                summed_result = np.zeros(n_points)
                orientation_combinations = list(itertools.product([-1, 1], repeat=len(self.edge_tags)))
                for signs in orientation_combinations:
                    orientation_array = np.tile(np.array(signs), (n_points, 1))
                    term_result = _evaluate_with_momentum(momentum_array, orientation_array)
                    summed_result += term_result
                return summed_result
            
            stability_mask = self._rotation_stability_mask(
                result, 
                sampler_result.loop_momentum_array, 
                sampler_result.weight_array[:, 0],
                _evaluate_with_momentum_summed,
            )
        else:
            stability_mask = self._rotation_stability_mask(
                result, 
                sampler_result.loop_momentum_array, 
                sampler_result.weight_array[:, 0],
                _evaluate_with_momentum,
            )

        # Create success array and zero out unstable results
        success = np.ones(n_points, dtype=np.int32)
        success[stability_mask] = 0
        result[stability_mask] = 0.0  # This can be removed once the fallback to higher precision is implemented

        end_time = perf_counter()
        self.timing_us_per_point = 1e6 * (end_time - start_time) / n_points
        return IntegrandResult(
            values=result,
            success=success,
            timing_us_per_point=self.timing_us_per_point
        )
