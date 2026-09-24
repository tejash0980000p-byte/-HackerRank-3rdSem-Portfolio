# Problem 5: Sparse Arrays

## Overview
Given a collection of $N$ input strings `stringList` and $Q$ query strings `queries`, determine how many times each query string occurs in `stringList`.

## Algorithmic Efficiency Comparison

### Approach A: Brute Force Nested Loop
- Compare every query $q_j$ against all $N$ input strings using `strcmp`.
- **Time Complexity:** $\mathcal{O}(N \times Q \times L)$ where $L$ is max string length.
- **Drawback:** Inefficient for large $N, Q$.

### Approach B: Hash Map Frequency Table (Implemented in C)
- Build a custom chaining hash table using the **djb2 hash algorithm**.
- Phase 1: Insert all $N$ input strings into the hash table, keeping track of frequencies.
- Phase 2: For each of the $Q$ query strings, look up its frequency in $\mathcal{O}(1)$ average time.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N + Q)$  
  Inserting $N$ items takes $\mathcal{O}(N)$ average time. Performing $Q$ lookups takes $\mathcal{O}(Q)$ average time.
- **Space Complexity:** $\mathcal{O}(N)$  
  The hash table stores at most $N$ unique string nodes with their frequency counters.
