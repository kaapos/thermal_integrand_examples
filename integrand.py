import numpy as np
from dataclasses import dataclass
from abc import ABC, abstractmethod

@dataclass
class IntegrandResult:
    """Result of an integrand evaluation.
    
    Attributes:
        values: Array of computed values for each input point
        success: Array of success flags (1 for success, 0 for failure)
        timing_us_per_point: Average computation time in microseconds per point
    """
    values: np.ndarray
    success: np.ndarray
    timing_us_per_point: float

class Integrand(ABC):
    """Abstract base class for integrand evaluators."""

    def __init__(self, params: np.ndarray, path_to_example: str):
        """Initialize the integrand evaluator.
        
        Args:
            params: Array of physical parameters
            path_to_example: Path to the example directory containing src (e.g., 'examples/sunset2')
        """
        self.params = np.asarray(params, dtype=np.float64)
        self.n_params = len(self.params)
        self.path_to_example = path_to_example
        self.timing_us_per_point = 0.0

    @abstractmethod
    def evaluate(self, jacobian_array: np.ndarray, loop_momentum_array: np.ndarray) -> IntegrandResult:
        """Evaluate the integrand for given momenta and jacobian.
        
        Args:
            jacobian_array: 1D array of jacobian values, shape (n_points,)
            loop_momentum_array: Array of loop momenta, shape (n_points, n_loops, dim)
            
        Returns:
            IntegrandResult containing the computed values, success flags, and timing
            
        Raises:
            ValueError: If input arrays have incompatible shapes
        """
        pass

    def set_params(self, **kwargs):
        """Update the parameters of the integrand."""
        for key, value in kwargs.items():
            if key in self.__dict__:
                setattr(self, key, value)
            else:
                raise ValueError(f"Invalid parameter: {key}")

