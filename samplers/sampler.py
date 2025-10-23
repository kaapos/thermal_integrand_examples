import numpy as np
from dataclasses import dataclass, field
from abc import ABC, abstractmethod
from symbolica import Sample
from typing import List

@dataclass(frozen=True, slots=True)
class SamplerResult:
    """Result of a sampling operation.
    
    Attributes:
        weight_array: Array of sampler weights for each point
        jacobian_array: Array of jacobian values for each point
        loop_momentum_array: Array of loop momenta for each point
        timing_us_per_point: Average computation time in microseconds per point
    """
    weight_array: np.ndarray
    jacobian_array: np.ndarray
    loop_momentum_array: np.ndarray
    timing_us_per_point: float = 0.0

@dataclass(frozen=True, slots=True)
class OrientedSamplerResult(SamplerResult):
    """Result of a sampling operation with orientation vectors.
    
    Extends SamplerResult by additionally carrying per-point orientation vectors.
    
    Attributes:
        orientation_vector_array: Array of orientation vectors for each point
    """
    orientation_vector_array: np.ndarray = field(
        default_factory=lambda: np.empty((0,), dtype=np.float64)
    )

class Sampler(ABC):
    """Abstract base class for samplers."""

    def __init__(self, params: np.ndarray, path_to_example: str):
        """Initialize the sampler.
        
        Args:
            params: Array of physical parameters
            path_to_example: Path to the example directory containing src (e.g., 'examples/sunset2')
        """
        self.params = np.asarray(params, dtype=np.float64)
        self.n_params = len(self.params)
        self.path_to_example = path_to_example
        self.x_size = 0
        self.continuous_size = 0
        self.discrete_shape = ()
        self.timing_us_per_point = 0.0

    @abstractmethod
    def sample(self, x: np.ndarray) -> SamplerResult:
        """Generate phase space points from points in the unit hypercube.
        
        Args:
            x: Input array for sampling, shape (n_points, x_size)
            
        Returns:
            SamplerResult containing weights, jacobians, loop momenta, and timing
            
        Raises:
            ValueError: If input array has wrong shape
        """
        pass

    @abstractmethod
    def sample_symbolica(self, x: List[Sample]) -> SamplerResult:
        """Generate phase space points from Symbolica samples.
        
        Args:
            x: List of n_points Symbolica samples, each with continuous_size continuous dimensions and discrete_shape discrete dimensions
            
        Returns:
            SamplerResult containing weights, jacobians, loop momenta, and timing
            
        Raises:
            ValueError: If the samples are not valid
        """
        pass

    @abstractmethod
    def get_nstrat(self, neval: int) -> list[int]:
        """Calculate nstrat for this sampler given neval."""
        pass

    def set_params(self, **kwargs):
        """Update the parameters of the sampler."""
        for key, value in kwargs.items():
            if key in self.__dict__:
                setattr(self, key, value)
            else:
                raise ValueError(f"Invalid parameter: {key}")

