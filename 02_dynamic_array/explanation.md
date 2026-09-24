# Problem 2: Dynamic Array

## Overview
Implement a 2D dynamic sequence data structure `arr` containing $N$ 1D dynamic arrays (sequences), indexed $0$ to $N-1$, initialized to empty.  
Maintain a state variable `lastAnswer` initialized to `0`.

Process $Q$ queries of two types:
1. **Query 1 ($1, x, y$):**  
   - Calculate $\text{idx} = (x \oplus \text{lastAnswer}) \pmod N$.  
   - Append integer $y$ to sequence `arr[idx]`.
2. **Query 2 ($2, x, y$):**  
   - Calculate $\text{idx} = (x \oplus \text{lastAnswer}) \pmod N$.  
   - Calculate element index $\text{elem\_idx} = y \pmod {\text{size}(arr[\text{idx}])}$.  
   - Assign $\text{lastAnswer} = arr[\text{idx}][\text{elem\_idx}]$.  
   - Store / print $\text{lastAnswer}$.

## C Implementation Details
In standard C, dynamic 2D resizing is achieved using a custom `DynamicVector` structure containing a dynamic heap array `data`, current `size`, and `capacity`. Geometric doubling (`capacity *= 2` on overflow via `realloc`) guarantees $\mathcal{O}(1)$ amortized insertion time.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N + Q)$  
  Initial vector creation takes $\mathcal{O}(N)$ time. Processing each query takes $\mathcal{O}(1)$ amortized time for bitwise XOR, modulo, and array access.
- **Space Complexity:** $\mathcal{O}(N + Q)$  
  The $N$ dynamic sequence headers occupy $\mathcal{O}(N)$ memory, and the appended elements occupy at most $\mathcal{O}(Q)$ memory.
