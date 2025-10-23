#!/usr/bin/env python3
"""
Example usage of the StableStack class.

This demonstrates how to use multiple precision levels to handle
points that fail at lower precision levels.
"""

import numpy as np
from integrands.stable_stack import StableStack, PrecisionLevel
from integrands.symbolica_integrand import SymbolicaIntegrand
from integrands.symbolica_integrand_prec import SymbolicaIntegrandPrec
from samplers.sampler import SamplerResult
from time import perf_counter


def example_stable_stack():
    """Example of using the StableStack with multiple precision levels"""
    print("=== StableStack Example ===")

    # Set up parameters for the sunset example
    params = np.array([1.0, 2.0, 3.0])
    path_to_example = "examples/sunset"  # Path to the example

    print(f"Parameters: {params}")
    print(f"Example path: {path_to_example}")

    # Initialize integrand instances with different precision settings
    # Level 0: Fast evaluation (e.g., standard double precision)
    print("\n--- Initializing Level 0 (fast) ---")
    integrand_fast = SymbolicaIntegrand(
        params=params,
        path_to_example=path_to_example,
        force_rebuild=False,
        sum_orientations=True,
        runtime_summation=False,
        stability_tolerance=1e-14,
        stability_abs_threshold=1e-15,
        stability_abs_tolerance=1e-15,
        escalate_large_weight_multiplier=0.9,
        n_shots=3,
        rotation_seed=1337,
    )
    
    # Level 1: Higher precision (for points that fail at level 0)
    print("\n--- Initializing Level 1 (precise) ---")
    integrand_precise = SymbolicaIntegrandPrec(
        params=params,
        path_to_example=path_to_example,
        sum_orientations=True,
        runtime_summation=False,
        prec=200,
        n_shots=1,
        escalate_large_weight_multiplier=-1.0,
    )

    print(f"\nIntegrand properties:")
    print(f"  Dimension: {integrand_fast.dim}")
    print(f"  Number of edges: {integrand_fast.n_edges}")
    print(f"  Number of loops: {integrand_fast.n_loops}")
    print(f"  Number of parameters: {integrand_fast.n_params}")

    # Create the StableStack with multiple levels
    print("\n--- Setting up StableStack ---")
    stack = StableStack([
        PrecisionLevel(integrand=integrand_fast, level_id=0),
        PrecisionLevel(integrand=integrand_precise, level_id=1),
    ])
    print(f"Configured {len(stack.levels)} precision levels")

    # Generate some random test points
    n_points = 100000
    max_batch_size = 1000
    np.random.seed(42)
    weights = np.ones((n_points, 1))
    jacobians = np.random.rand(n_points)
    loop_momenta = np.random.rand(n_points, integrand_fast.n_loops, integrand_fast.dim)

    print(f"\n--- Evaluating {n_points} points through StableStack in batches ---")
    print(f"Batch size: {max_batch_size}")
    
    # Allocate arrays for results
    all_values = np.zeros(n_points, dtype=np.float64)
    all_success = np.zeros(n_points, dtype=np.int32)
    
    start_time = perf_counter()
    # Process in batches sequentially
    n_batches = (n_points + max_batch_size - 1) // max_batch_size
    for batch_idx in range(n_batches):
        start_idx = batch_idx * max_batch_size
        end_idx = min(start_idx + max_batch_size, n_points)
        batch_size = end_idx - start_idx
        
        # Create batch sampler result
        batch_sampler_result = SamplerResult(
            weight_array=weights[start_idx:end_idx],
            jacobian_array=jacobians[start_idx:end_idx],
            loop_momentum_array=loop_momenta[start_idx:end_idx, :, :]
        )
        
        # Evaluate batch
        batch_result = stack.evaluate(batch_sampler_result)
        
        # Store results
        all_values[start_idx:end_idx] = batch_result.values
        all_success[start_idx:end_idx] = batch_result.success

    end_time = perf_counter()
    total_time_us = 1e6 * (end_time - start_time)
    # Calculate average timing per point
    avg_timing_us_per_point = total_time_us / n_points if n_points > 0 else 0.0

    print(f"\n✓ Evaluation completed!")
    print(f"  Total points processed: {n_points}")
    print(f"  Number of batches: {n_batches}")
    print(f"  Average timing: {avg_timing_us_per_point:.2f} μs per point")
    print(f"  Value statistics:")
    print(f"    Mean: {np.mean(all_values):.6e}")
    print(f"    Std:  {np.std(all_values):.6e}")
    print(f"    Min:  {np.min(all_values):.6e}")
    print(f"    Max:  {np.max(all_values):.6e}")
    print(f"  Success rate: {np.mean(all_success) * 100:.1f}%")

    # Get statistics for each level
    print(f"\n--- Per-Level Statistics ---")
    stats = stack.get_and_reset_stats()
    print(f"Total points processed: {stats['total_points']}")
    for level_stat in stats['levels']:
        print(f"\nLevel {level_stat['level_id']}:")
        print(f"  Processed: {level_stat['processed']}")
        print(f"  Resolved:  {level_stat['resolved']}")
        if level_stat['processed'] > 0:
            resolve_rate = (level_stat['resolved'] / level_stat['processed']) * 100
            print(f"  Resolve rate: {resolve_rate:.1f}%")
        print(f"  Time: {level_stat['time_us']:.2f} μs")
        print(f"  Avg time per point: {level_stat['avg_us_per_point']:.2f} μs")

if __name__ == "__main__":
    try:
        example_stable_stack()
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()