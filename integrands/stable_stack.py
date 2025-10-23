import numpy as np
from dataclasses import dataclass
from typing import List, Optional

from samplers.sampler import SamplerResult, OrientedSamplerResult
from .integrand import Integrand, IntegrandResult


@dataclass
class PrecisionLevel:
    """Precision level for one integrand in StableStack.

    - integrand: Integrand instance
    - level_id: optional identifier for this level
    """
    integrand: Integrand
    level_id: int = 0


class StableStack:
    """Routes unresolved points through multiple precision levels.

    Usage pattern:
      - Level 0: fast integrand
      - Levels 1..N: progressively more precise integrands

    Only unresolved points (success == 0) are forwarded to the next level.
    """

    def __init__(self, levels: List[PrecisionLevel]):
        if not levels:
            raise ValueError("levels must be a non-empty list")
        self.levels = levels
        
        # Per-level accounting (accumulates between get_and_reset_stats calls)
        self._processed = np.zeros(len(levels), dtype=np.int64)
        self._resolved = np.zeros(len(levels), dtype=np.int64)
        self._time_us = np.zeros(len(levels), dtype=np.float64)
        self._meta = []
        for lvl in levels:
            meta_entry = {
                "level_id": lvl.level_id,
            }
            self._meta.append(meta_entry)
        self._last_total_points = 0
        self.max_weight = 0.0

    @staticmethod
    def _subset(sr: SamplerResult, idx: np.ndarray) -> SamplerResult:
        """Extract a subset of sampler results based on indices."""
        if isinstance(sr, OrientedSamplerResult):
            return OrientedSamplerResult(
                weight_array=sr.weight_array[idx],
                jacobian_array=sr.jacobian_array[idx],
                loop_momentum_array=sr.loop_momentum_array[idx, ...],
                timing_us_per_point=sr.timing_us_per_point,
                orientation_vector_array=sr.orientation_vector_array[idx, ...],
            )
        else:
            return SamplerResult(
                weight_array=sr.weight_array[idx],
                jacobian_array=sr.jacobian_array[idx],
                loop_momentum_array=sr.loop_momentum_array[idx, ...],
                timing_us_per_point=sr.timing_us_per_point,
            )

    def evaluate(self, sampler_result: SamplerResult) -> IntegrandResult:
        """Evaluate sampler results through the stack of precision levels.
        
        Args:
            sampler_result: Input sampler result to evaluate
            
        Returns:
            IntegrandResult with values and success flags for all points
        """
        n = sampler_result.jacobian_array.shape[0]
        if sampler_result.loop_momentum_array.shape[0] != n:
            raise ValueError("SamplerResult arrays must have matching first dimension")

        values = np.zeros(n, dtype=np.float64)
        success = np.zeros(n, dtype=np.int32)
        unresolved = np.ones(n, dtype=bool)

        # Remember batch size for stats reporting
        self._last_total_points = int(n)

        for level_i, lvl in enumerate(self.levels):
            if not unresolved.any():
                break
            idx = np.flatnonzero(unresolved)
            sub_sr = self._subset(sampler_result, idx)

            res = lvl.integrand.evaluate(sub_sr, max_weight=self.max_weight)

            self.max_weight = max(self.max_weight, lvl.integrand.max_weight)

            # Update resolved points
            m = res.success.astype(bool)
            if m.any():
                values[idx[m]] = res.values[m]
                success[idx[m]] = 1
                unresolved[idx[m]] = False
            
            # Accounting
            self._processed[level_i] += idx.size
            self._resolved[level_i] += int(np.count_nonzero(m))
            # Use integrand-reported average time per point when available
            if res.timing_us_per_point:
                self._time_us[level_i] += float(res.timing_us_per_point) * float(idx.size)

        # Average timing per input point across the whole batch
        total_time_us = float(np.sum(self._time_us))
        avg_batch_us_per_point = (total_time_us / float(n)) if n > 0 else 0.0
        return IntegrandResult(values=values, success=success, timing_us_per_point=avg_batch_us_per_point)

    def get_and_reset_stats(self, total_points: Optional[int] = None) -> dict:
        """Return per-level stats since last reset and clear the counters.

        Args:
            total_points: if provided, included in the returned dict; otherwise uses last batch size.
            
        Returns:
            Dictionary with per-level statistics and total points processed
        """
        levels_stats = []
        for i, meta in enumerate(self._meta):
            processed_i = int(self._processed[i])
            time_us_i = float(self._time_us[i])
            avg_us = (time_us_i / processed_i) if processed_i > 0 else 0.0
            entry = {
                "level_id": int(meta["level_id"]),
                "processed": processed_i,
                "resolved": int(self._resolved[i]),
                "time_us": time_us_i,
                "avg_us_per_point": avg_us,
            }
            levels_stats.append(entry)
        out = {
            "levels": levels_stats,
            "total_points": int(self._last_total_points if total_points is None else total_points),
        }
        # Reset
        self._processed[:] = 0
        self._resolved[:] = 0
        self._time_us[:] = 0.0
        self._last_total_points = 0
        return out

