# Problem 1: Diagonal Difference

## Overview
Given a square matrix $A$ of size $N \times N$, calculate the absolute difference between the sums of its two diagonals:
- **Primary Diagonal**: Top-left to bottom-right elements $A[i][i]$ for $0 \le i < N$.
- **Secondary Diagonal**: Top-right to bottom-left elements $A[i][N - 1 - i]$ for $0 \le i < N$.

## Mathematical Formulation
$$\text{Difference} = \left| \sum_{i=0}^{N-1} A[i][i] - \sum_{i=0}^{N-1} A[i][N - 1 - i] \right|$$

## Algorithm Step-by-Step
1. Initialize `primary_sum = 0` and `secondary_sum = 0`.
2. Iterate `i` from `0` to `N - 1`:
   - Add `A[i][i]` to `primary_sum`.
   - Add `A[i][N - 1 - i]` to `secondary_sum`.
3. Compute and return `abs(primary_sum - secondary_sum)`.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$  
  Only a single loop over $N$ rows is required. We perform 2 additions per iteration.
- **Space Complexity:** $\mathcal{O}(1)$ Auxiliary Space  
  Only scalar variables (`primary_sum`, `secondary_sum`) are maintained during computation.
