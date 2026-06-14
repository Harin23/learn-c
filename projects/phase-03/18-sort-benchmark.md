# Project 18: Sort Benchmark Suite (Phase 3 Capstone)

**Modules:** 3.4–3.5 — Algorithmic Thinking and Performance Analysis  
**Estimated time:** 6–8 hours

## Description

Benchmark insertion sort and merge sort (minimum) on random integer arrays at increasing sizes. Write an analysis document comparing theoretical and measured results.

## File Layout

```
sortbench/
├── Makefile
├── sort.h
├── sort.c          /* insertion_sort, merge_sort */
├── bench.h
├── bench.c         /* timing harness */
├── main.c
└── ANALYSIS.md
```

## Requirements

### Algorithms (sort.c)

```c
void insertion_sort(int *arr, size_t n);
void merge_sort(int *arr, size_t n);   /* may use temp buffer */
```

Verify correctness before benchmarking (compare to known-sorted copy).

### Benchmark Harness (bench.c)

- Use `clock_gettime(CLOCK_MONOTONIC, ...)`
- Generate random arrays with fixed seed (`srand(42)`) for reproducibility
- Test sizes: at least `n = 1000, 5000, 10000, 50000` (skip insertion sort on largest if >60s — document skip)
- Report milliseconds per sort per size
- Print table to stdout

Example output:

```
       n | insertion_ms | merge_ms
    1000 |         12.3 |      0.8
    5000 |        280.1 |      4.2
   10000 |       1120.5 |      9.1
```

### ANALYSIS.md

Include:

1. Big-O of each algorithm implemented
2. Table of measured results (copy from program output)
3. Discussion: does data match theory? Why might constants differ?
4. One paragraph on when insertion sort might still be used in practice (small n, nearly sorted)

## Rubric

| Criterion | Points |
|-----------|--------|
| Both sorts correct | 25 |
| Timing harness uses monotonic clock | 15 |
| At least 4 sizes benchmarked | 15 |
| Reproducible random data (fixed seed) | 10 |
| ANALYSIS.md complete and thoughtful | 25 |
| Zero warnings | 10 |
| **Total** | **100** |

## Optional Extensions

- Add quicksort and compare
- Plot results with Python/gnuplot (mention in ANALYSIS)
- Compare `qsort` from libc as reference

## Starters

- [labs/phase-03/insertion_sort_starter.c](../../labs/phase-03/insertion_sort_starter.c)
- [labs/phase-03/merge_sort_starter/](../../labs/phase-03/merge_sort_starter/)
- [labs/phase-03/timing_starter.c](../../labs/phase-03/timing_starter.c)

## Phase 3 Completion

Passing this project (≥80 rubric points) plus Valgrind-clean Projects 13–17 completes Phase 3.
