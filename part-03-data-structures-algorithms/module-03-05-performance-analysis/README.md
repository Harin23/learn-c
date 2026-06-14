# Module 3.5 — Performance Analysis

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Express algorithm complexity in Big-O notation
- Distinguish best, average, and worst cases
- Measure runtime empirically with `clock_gettime`
- Compare algorithms fairly with controlled input sizes
- Write a concise performance report with tables and conclusions
- Relate theoretical complexity to measured curves

## Prerequisites

- Completed [Module 3.4](../module-03-04-algorithmic-thinking/README.md) exit criteria

## Concepts to Study

1. **Big-O notation** — upper bound; drop constants and lower-order terms
2. **Common classes** — O(1), O(log n), O(n), O(n log n), O(n²)
3. **Amortized analysis preview** — dynamic array append; hash table resize
4. **Empirical benchmarking** — same hardware, warm vs cold cache effects
5. **`clock_gettime(CLOCK_MONOTONIC, ...)`** — elapsed wall time in C
6. **Input size scaling** — test n = 100, 1000, 10000, 100000
7. **Fair comparison** — same random seed, same data copies per algorithm
8. **When theory diverges from practice** — constants, cache, compiler optimization

## Hands-On Labs

### Lab 1: Timing Hello

Write a program that times a busy loop using `clock_gettime`. Link with `-lrt` if needed on older systems (glibc 2.17+ often has it in libc).

Starter: [labs/part-03/timing_starter.c](../../labs/part-03/timing_starter.c)

### Lab 2: O(n²) vs O(n log n) Crossover

Plot or tabulate insertion sort vs merge sort times at increasing n. Find approximate crossover point on your machine.

### Lab 3: Hash Map vs BST Lookup

Compare average lookup time for hash map vs BST with 10,000 string keys (same key set).

Uses Projects 16 and 17 implementations.

### Lab 4: Read `/proc/cpuinfo`

Skim CPU model and cache info. One paragraph: how might cache affect benchmark results?

## Mini-Project (Part 3 Capstone)

**Sort Benchmark Suite** — [projects/part-03/18-sort-benchmark.md](../../projects/part-03/18-sort-benchmark.md)

Includes written `ANALYSIS.md` comparing theory to measurements.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| CLRS, Ch. 2 | Asymptotic notation |
| `man 3 clock_gettime` | Timing |
| Brendan Gregg — systems performance mindset | Preview for Part 5–6 |

## Part 3 Oral Checklist (Self-Assessment)

Answer without notes:

1. Big-O of hash table average lookup? Worst case?
2. Big-O of BST search on balanced vs skewed tree?
3. Why is merge sort O(n log n)?
4. When would you choose a hash table over a BST?
5. What does Valgrind not measure?

## Exit Criteria

Before advancing to Part 4, confirm:

- [ ] Sort benchmark project complete with `ANALYSIS.md`
- [ ] Measurements cover at least 4 input sizes per algorithm
- [ ] Insertion sort vs merge sort comparison included
- [ ] All Part 3 projects (13–18) Valgrind-clean
- [ ] Part 3 oral checklist completed confidently
- [ ] [Part 3 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 4 — Linux User-Space Development](../../part-04-linux-user-space/) (coming soon)
