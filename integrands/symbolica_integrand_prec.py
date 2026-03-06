import numpy as np
import os
from symbolica import *
from .symbolica_integrand import SymbolicaIntegrand
import gc
from decimal import Decimal, getcontext, localcontext, Context
import itertools

# Suppress warnings about small numbers
import warnings
warnings.filterwarnings('ignore', message='.*smallest.*subnormal.*')


class SymbolicaIntegrandPrec(SymbolicaIntegrand):
    """Arbitrary-precision Symbolica integrand using evaluate_with_prec().
    
    This class mirrors SymbolicaIntegrand's API but evaluates the integrand via
    Symbolica's high-precision evaluator rather than a compiled double-precision evaluator.
    """

    def __init__(
        self,
        params: np.ndarray,
        path_to_example: str,
        force_rebuild: bool = False,
        prec: int = 80,
        stability_tolerance: float = 1e-3,
        stability_abs_tolerance: float = 1e-15,
        stability_abs_threshold: float = 1e-12,
        escalate_large_weight_multiplier: float = -1.0,
        escalate_small_momentum_multiplier: float = -1.0,
        escalate_large_momentum_multiplier: float = -1.0,
        rotation_seed: int = None,
        n_shots: int = 3,
        sum_orientations: bool = True,
        runtime_summation: bool = False
    ):
        """Initialize the integrand.
        
        Args:
            params: Array of physical parameters
            path_to_example: Path to the example directory containing src (e.g., 'examples/sunset2')
            force_rebuild: Force rebuilding the high-precision evaluator even if it exists
            prec: Precision for the high-precision evaluator
            stability_tolerance: Threshold for the relative stability check
            stability_abs_tolerance: Threshold for the absolute stability check
            stability_abs_threshold: Threshold for the switch between absolute and relative stability check
            escalate_large_weight_multiplier: Escalate to high precision if the weight is larger than this multiplier times the maximum weight. If negative, do not escalate.
            escalate_small_momentum_multiplier: Escalate to high precision if any of the loop momenta is smaller than this multiplier times the unit energy. If negative, do not escalate.
            escalate_large_momentum_multiplier: Escalate to high precision if any of the loop momenta is larger than this multiplier times the unit energy. If negative, do not escalate.
            rotation_seed: Seed for the random rotation matrix
            n_shots: Number of evaluations in stability check (original + n_shots-1 rotations)
            sum_orientations: Whether to sum over all orientations
            runtime_summation: If True and sum_orientations=True, sum orientations at runtime instead of pre-compiling them. Reduces memory but increases evaluation time.
        """
        # We do not need force_rebuild for the base class; pass False to the base
        super().__init__(
            params=params,
            path_to_example=path_to_example,
            force_rebuild=False,
            stability_tolerance=stability_tolerance,
            stability_abs_tolerance=stability_abs_tolerance,
            stability_abs_threshold=stability_abs_threshold,
            escalate_large_weight_multiplier=escalate_large_weight_multiplier,
            escalate_small_momentum_multiplier=escalate_small_momentum_multiplier,
            escalate_large_momentum_multiplier=escalate_large_momentum_multiplier,
            rotation_seed=rotation_seed,
            n_shots=n_shots,
            build_eagerly=False,
            sum_orientations=sum_orientations,
            runtime_summation=runtime_summation
        )
        self.force_rebuild = bool(force_rebuild)
        self.prec = int(prec)
        self._evaluator = None
        # Build evaluator
        self._ensure_evaluator()

    def __getstate__(self):
        state = super().__getstate__()
        state['_evaluator'] = None
        return state

    def __setstate__(self, state):
        super().__setstate__(state)
        self._evaluator = None

    def _to_decimal(self, value):
        """Convert value to Decimal and pad trailing zeros up to self.prec."""
        if isinstance(value, Decimal):
            dec = value
        else:
            dec = Decimal(str(value))

        if not dec.is_finite():
            return dec

        fractional_digits = -dec.as_tuple().exponent if dec.as_tuple().exponent < 0 else 0
        if fractional_digits >= self.prec:
            # print(f"Fractional digits are already greater than or equal to self.prec. Returning original value.")
            return dec

        target = Decimal(1).scaleb(-self.prec)

        dec_tuple = dec.as_tuple()
        # quantize() can raise InvalidOperation if context precision is too small
        # for the coefficient after scale alignment. Size context dynamically.
        digits_in_coeff = len(dec_tuple.digits)
        extra_scale_digits = max(0, dec_tuple.exponent + self.prec)
        required_prec = max(self.prec + 10, digits_in_coeff + extra_scale_digits + 10, 64)
        with localcontext(Context(prec=required_prec)):
            return dec.quantize(target)

    def _ensure_evaluator(self):
        """Prepare the high-precision evaluator."""
        if self._evaluator is not None:
            return

        build_dir = os.path.join(self.path_to_example, "build", "symbolica_integrand")
        os.makedirs(build_dir, exist_ok=True)
        example_name = os.path.basename(os.path.normpath(self.path_to_example))
        if self.sum_orientations and not self.runtime_summation:
            evaluator_path = os.path.join(build_dir, f"integrand_{example_name}.evaluator")
        else:
            evaluator_path = os.path.join(build_dir, f"integrand_{example_name}_rho_term.evaluator")

        def _tanh_decimal(x: Decimal) -> Decimal:
            # tanh(x) = sign(x) * (1 - e^{-2|x|})/(1 + e^{-2|x|})
            with localcontext(Context(prec=self.prec)):
                ctx = getcontext()
                ax = x.copy_abs()
                t = ctx.exp(Decimal(-2) * ax)
                y = (Decimal(1) - t) / (Decimal(1) + t)
                return self._to_decimal(-y if x.is_signed() else y)
        
        def _coth_decimal(x: Decimal) -> Decimal:
            # coth(x) = sign(x) * (1 + e^{-2|x|})/(1 - e^{-2|x|}), singular at x=0
            with localcontext(Context(prec=self.prec)):
                if x == 0:
                    return Decimal('Infinity')
                ctx = getcontext()
                ax = x.copy_abs()
                t = ctx.exp(Decimal(-2) * ax)
                den = (Decimal(1) - t)
                if den == 0:
                    return Decimal('-Infinity') if x.is_signed() else Decimal('Infinity')
                y = (Decimal(1) + t) / den
                return self._to_decimal(-y if x.is_signed() else y)
        
        def _sech_decimal(x: Decimal) -> Decimal:
            # sech(x) = 2 e^{-|x|} / (1 + e^{-2|x|}) = 2 t / (1 + t^2)
            with localcontext(Context(prec=self.prec)):
                ctx = getcontext()
                ax = x.copy_abs()
                t = ctx.exp(-ax)
                return self._to_decimal((Decimal(2) * t) / (Decimal(1) + t * t))
        
        def _csch_decimal(x: Decimal) -> Decimal:
            # csch(x) = sign(x) * 2 e^{-|x|} / (1 - e^{-2|x|}) = sign(x) * 2 t / (1 - t^2)
            with localcontext(Context(prec=self.prec)):
                if x == 0:
                    return Decimal('Infinity')
                ctx = getcontext()
                ax = x.copy_abs()
                t = ctx.exp(-ax)
                den = (Decimal(1) - t * t)
                if den == 0:
                    return Decimal('-Infinity') if x.is_signed() else Decimal('Infinity')
                y = (Decimal(2) * t) / den
                return self._to_decimal(-y if x.is_signed() else y)
        
        external_functions = {
            (S("Tanh"), "tanh"): lambda args: _tanh_decimal(args[0]),
            (S("Coth"), "coth"): lambda args: _coth_decimal(args[0]),
            (S("Sech"), "sech"): lambda args: _sech_decimal(args[0]),
            (S("Csch"), "csch"): lambda args: _csch_decimal(args[0]),
        }

        if (not self.force_rebuild) and os.path.exists(evaluator_path) and os.path.getsize(evaluator_path) > 0:
            with open(evaluator_path, "rb") as f:
                evaluator_bytes = f.read()
            self._evaluator = Evaluator.load(evaluator_bytes, external_functions=external_functions)
            return

        loop_momentum_vars = [S(x) for x in self.config["loop_momentum_components"]]
        if self.sum_orientations and not self.runtime_summation:
            sign_vars = []
        else:
            sign_vars = [S(f"rho_{tag}") for tag in self.edge_tags]
        param_vars = [S(x) for x in self.config["parameters"]]
        vars_list = loop_momentum_vars + sign_vars + param_vars

        functions = {}
        functions[(S("ose"), "ose", (S("sp"), S("m")))] = E("sqrt(sp+m^2)")

        dot_products = self.config["dot_products"]

        for sp_name, expression_str in dot_products.items():
            functions[(S(sp_name), sp_name, tuple(loop_momentum_vars))] = E(expression_str)

        # Read integrand as Symbolica expression
        integrand_expr = E(open(os.path.join(self.path_to_example, "src", "symbolica_integrand", "integrand.txt")).read())

        if self.sum_orientations and not self.runtime_summation:
            # Pre-compute sum over all orientations
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

        self._evaluator = integrand.evaluator(
            {},
            functions,
            vars_list,
            iterations=0,
            external_functions=external_functions
        )
        with open(evaluator_path, "wb") as f:
            f.write(self._evaluator.save())
        self.force_rebuild = False
        gc.collect()

    def _evaluate_variables(self, variables: np.ndarray) -> np.ndarray:
        """Evaluate using high-precision evaluator."""
        variables_dec = [[self._to_decimal(v) for v in row] for row in variables]
        values_dec = [self._evaluator.evaluate_with_prec(row_dec, decimal_digit_precision=self.prec) for row_dec in variables_dec]
        # Convert Decimals to float64 for downstream compatibility
        return np.array([float(v[0]) for v in values_dec], dtype=np.float64).ravel()