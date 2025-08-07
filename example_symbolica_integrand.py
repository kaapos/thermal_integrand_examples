#!/usr/bin/env python3
"""
Example usage of the SymbolicaIntegrand class.
"""

import numpy as np
from symbolica_integrand import SymbolicaIntegrand

def example_symbolica_integrand():
    """Example of using the SymbolicaIntegrand"""
    print("=== SymbolicaIntegrand Example ===")

    # Set up parameters for the sunset2T example
    params = np.array([1.0, 2.0, 3.0, ])  # Physical parameters: mUV, mu, 1/T
    path_to_example = "examples/sunset2T"  # Path to the example

    print(f"Parameters: {params}")
    print(f"Example path: {path_to_example}")

    # Initialize the integrand
    integrand = SymbolicaIntegrand(
        params=params,
        path_to_example=path_to_example,
        force_rebuild=False,
        do_stability_check=True,
        stability_tolerance=1e-7,
        stability_abs_threshold=1e-15,
        rotation_seed=42,
        n_shots = 4
    )

    print(f"\nIntegrand properties:")
    print(f"  Dimension: {integrand.dim}")
    print(f"  Number of edges: {integrand.n_edges}")
    print(f"  Number of loops: {integrand.n_loops}")
    print(f"  Number of parameters: {integrand.n_params}")

    # Generate some random jacobian and loop momentum input
    n_points = 10000
    np.random.seed(42)
    jacobians = np.random.rand(n_points)
    loop_momenta = np.random.rand(n_points, integrand.n_loops, integrand.dim)

    print(f"\nEvaluating integrand for {n_points} points...")
    result = integrand.evaluate(jacobian_array=jacobians, loop_momentum_array=loop_momenta)

    print(f"✓ Evaluation completed!")
    print(f"  Values shape: {result.values.shape}")
    print(f"  Success flags shape: {result.success.shape}")
    print(f"  Average timing: {result.timing_us_per_point:.2f} μs per point")
    print(f"  Value statistics:")
    print(f"    Mean: {np.mean(result.values):.6e}")
    print(f"    Std:  {np.std(result.values):.6e}")
    print(f"    Min:  {np.min(result.values):.6e}")
    print(f"    Max:  {np.max(result.values):.6e}")
    print(f"  Success rate: {np.mean(result.success) * 100:.1f}%")

    # Demonstrate parameter updating
    print(f"\n--- Updating parameters ---")
    new_params = np.array([2.0, 4.0, 6.0])
    integrand.set_params(params=new_params)
    print(f"Updated parameters: {integrand.params}")

    # Evaluate again with new parameters
    result2 = integrand.evaluate(jacobian_array=jacobians[:10], loop_momentum_array=loop_momenta[:10])
    print(f"New values: {result2.values[:5]}")

if __name__ == "__main__":
    try:
        example_symbolica_integrand()
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc() 