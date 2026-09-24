# Activity 8 Studio Deliverable Report
## 3rd Semester B.Tech (Computer Science & Engineering) | Portfolio ID: B25CS0311

---

## 1. Student Details & Repository Links

- **Student Name:** `Tejas H`
- **Roll Number:** `B25CS0311`
- **GitHub Repository URL:** [https://github.com/tejash0980000p-byte/-HackerRank-3rdSem-Portfolio](https://github.com/tejash0980000p-byte/-HackerRank-3rdSem-Portfolio)
- **HackerRank Profile URL:** [https://www.hackerrank.com/tejash0980000p](https://www.hackerrank.com/tejash0980000p)

---

## 2. Summary Table of Time & Space Complexities

| # | Problem Name | Topic / Category | Key Concept Evaluated | Target Complexity | Achieved Complexity | Status |
| :-: | :--- | :--- | :--- | :--- | :--- | :-: |
| **1** | **Diagonal Difference** | 2D Arrays / Matrices | Matrix traversal, diagonal sum | Time: $\mathcal{O}(N)$, Space: $\mathcal{O}(1)$ | Time: $\mathcal{O}(N)$, Space: $\mathcal{O}(1)$ | **Accepted** |
| **2** | **Dynamic Array** | Data Structures / Vectors | 2D nested sequence, bitwise XOR | Time: $\mathcal{O}(N + Q)$, Space: $\mathcal{O}(N)$ | Time: $\mathcal{O}(N + Q)$, Space: $\mathcal{O}(N+Q)$ | **Accepted** |
| **3** | **Time Conversion** | Strings & Logic | 12-hr AM/PM to 24-hr military time | Time: $\mathcal{O}(1)$, Space: $\mathcal{O}(1)$ | Time: $\mathcal{O}(1)$, Space: $\mathcal{O}(1)$ | **Accepted** |
| **4** | **Compare Triplets** | Basic Implementation | Element-wise score tracking | Time: $\mathcal{O}(1)$, Space: $\mathcal{O}(1)$ | Time: $\mathcal{O}(1)$, Space: $\mathcal{O}(1)$ | **Accepted** |
| **5** | **Sparse Arrays** | Hash Maps / Strings | Frequency mapping with djb2 hash | Time: $\mathcal{O}(N + Q)$, Space: $\mathcal{O}(N)$ | Time: $\mathcal{O}(N + Q)$, Space: $\mathcal{O}(N)$ | **Accepted** |

---

## 3. HackerRank 3-Star Badge & Submission Screenshots

### HackerRank 3-Star Badge
![HackerRank 3-Star Badge](docs/screenshots/hackerrank_badge.png)

### Screenshots of Accepted Submissions
1. **Diagonal Difference:** `docs/screenshots/01_diagonal_difference_accepted.png`
2. **Dynamic Array:** `docs/screenshots/02_dynamic_array_accepted.png`
3. **Time Conversion:** `docs/screenshots/03_time_conversion_accepted.png`
4. **Compare the Triplets:** `docs/screenshots/04_compare_triplets_accepted.png`
5. **Sparse Arrays:** `docs/screenshots/05_sparse_arrays_accepted.png`

---

## 4. Reflective Summary on Algorithmic Optimization Techniques Learned (Exact 200 Words)

During Activity 8, I systematically explored foundational computer science algorithmic paradigms across linear data structures, 2D matrix manipulation, string parsing, and hash-based retrieval in C language.

Solving **Diagonal Difference** reinforced matrix indexing efficiency, achieving $\mathcal{O}(N)$ time complexity by accumulating primary ($A[i][i]$) and secondary ($A[i][N-1-i]$) diagonal elements within a single linear pass while maintaining $\mathcal{O}(1)$ auxiliary space. In **Dynamic Array**, managing multi-sequence vectors required implementing geometric array expansion via `realloc`, guaranteeing $\mathcal{O}(1)$ amortized insertion time per query under $\mathcal{O}(N+Q)$ memory constraints. The **Time Conversion** challenge emphasized constant $\mathcal{O}(1)$ string parsing and conditional arithmetic logic to transform 12-hour AM/PM timestamps into 24-hour military format without any runtime overhead. **Compare the Triplets** demonstrated constant $\mathcal{O}(1)$ element-wise comparison and score accumulation across structured inputs. Finally, **Sparse Arrays** highlighted the clear performance contrast between brute-force $\mathcal{O}(N \times Q)$ nested linear searching and optimal hash map frequency mapping. By constructing a custom chained hash table utilizing the djb2 algorithm, query lookup efficiency was optimized to $\mathcal{O}(1)$ expected time, reducing overall total complexity to $\mathcal{O}(N+Q)$.

Overall, this comprehensive activity deepened my practical computer engineering expertise in selecting optimal data structures, managing heap dynamic memory in C safely, and balancing crucial space-time trade-offs for scalable software development applications.
