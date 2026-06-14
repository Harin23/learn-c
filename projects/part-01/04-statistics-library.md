# Project 4: Statistics Library

**Module:** 1.3 — Functions and Program Organization  
**Estimated time:** 4–5 hours

## Description

Build a multi-file C project that computes statistics over an integer array, demonstrating functions, headers, and Makefile usage.

## File Layout

```
stats/
├── Makefile
├── main.c
├── stats.h
└── stats.c
```

## API (stats.h)

Implement these functions:

```c
int stats_min(const int *data, size_t n);
int stats_max(const int *data, size_t n);
double stats_mean(const int *data, size_t n);
double stats_median(int *data, size_t n);  /* may reorder data */
```

- `n` is the number of elements; assume `n > 0` for simplicity
- `stats_median`: sort a **copy** of the array (do not destroy caller's data); return middle value (average of two middles if n is even)

## main.c Behavior

1. Read integers from stdin until EOF or non-integer input
2. Print min, max, mean, and median
3. If no integers read, print an error message and exit with code 1

Example:

```
$ echo "3 1 4 1 5" | ./stats
min: 1
max: 5
mean: 2.80
median: 3.00
```

## Makefile Requirements

Targets:

- `all` — build `stats` binary
- `clean` — remove `stats`, `*.o`

Variables:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
```

## Rubric

| Criterion | Points |
|-----------|--------|
| All four functions correct | 40 |
| Multi-file layout with header guard | 20 |
| Makefile builds cleanly | 15 |
| Median uses copy (caller data unchanged) | 15 |
| Zero warnings | 10 |
| **Total** | **100** |

## Test Cases

1. `[1]` → min=max=median=1, mean=1.0
2. `[1, 2, 3, 4]` → median = 2.5
3. `make clean && make` succeeds
4. Empty input → exit code 1

## Extension (Optional)

Add `stats_stddev` using a two-pass algorithm.
