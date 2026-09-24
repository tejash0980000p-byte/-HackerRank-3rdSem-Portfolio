# Problem 4: Compare the Triplets

## Overview
Compare two triplets of integers representing Alice's ratings $A = (a_0, a_1, a_2)$ and Bob's ratings $B = (b_0, b_1, b_2)$:
- If $a_i > b_i$, Alice earns $1$ point.
- If $a_i < b_i$, Bob earns $1$ point.
- If $a_i = b_i$, neither person earns a point.

Return an array containing $[ \text{Alice's score}, \text{Bob's score} ]$.

## Implementation Step-by-Step
1. Allocate an array `result` of size $2$, initializing both elements to `0`.
2. Loop index `i` from $0$ to $2$:
   - Compare `a[i]` and `b[i]`.
   - Increment `result[0]` if `a[i] > b[i]`.
   - Increment `result[1]` if `a[i] < b[i]`.
3. Return `result` with output count `2`.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(1)$  
  Executes exactly 3 iterations regardless of input magnitude.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses a fixed 2-element array for scores.
