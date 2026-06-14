# Phase 3 Resources

Canonical reading list for Phase 3 — Data Structures and Algorithms.

## Primary References

| Resource | Modules | Notes |
|----------|---------|-------|
| K&R, Chapter 5 | 3.1 | Lists, trees as linked structures |
| *Algorithms in C* (Robert Sedgewick), Parts 3–5 | 3.1–3.5 | Implementations focus |
| CLRS (*Introduction to Algorithms*), Ch. 2–4, 11–12 | 3.2–3.5 | Theory; optional but valuable |
| *Problem Solving with Algorithms and Data Structures* | 3.4 | [Free online](https://runestone.academy/ns/books/published/pythonds/index.html) — concepts transfer to C |

## Man Pages and Tools

```bash
man 3 qsort          # libc sort with comparator
man 3 clock_gettime  # benchmarking
man 1 valgrind       # memory checks on all projects
```

## Module Reading Map

| Module | Focus | Reading |
|--------|-------|---------|
| 3.1 | Lists, stacks, queues | Sedgewick Ch. 3; K&R Ch. 5 |
| 3.2 | Hash tables | CLRS Ch. 11; djb2 hash note |
| 3.3 | BST | CLRS Ch. 12; Sedgewick Ch. 12 |
| 3.4 | Algorithms | CLRS Ch. 2–4 |
| 3.5 | Big-O, benchmarks | CLRS Ch. 2; `man clock_gettime` |

## Linux and Systems Connections (Preview)

Structures you implement here appear throughout Linux:

| Your project | Linux analogue (Phase 7+) |
|--------------|---------------------------|
| Linked list | `struct list_head` in kernel |
| Hash map | dentry cache, symbol tables |
| BST / tree | VFS mount points, interval trees |
| Sort benchmark | kernel scheduler metrics mindset |

## Valgrind Habit

Run on every heap-based project:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./your_program
```

## Reading Order Summary

1. Sedgewick lists/stacks/queues + Module 3.1 + Projects 13–15
2. CLRS hash tables (or online summary) + Module 3.2 + Project 16
3. CLRS BST + Module 3.3 + Project 17
4. CLRS sorting + Module 3.4 labs
5. Big-O review + Module 3.5 + Project 18 `ANALYSIS.md`

## Gate to Phase 4

Phase 4 (Linux user-space) requires Phase 2 exit gate; completing Phase 3 first is strongly recommended so file I/O and process tools can use your ADT skills. Phase 3 exit gate must pass before treating yourself as ready for systems programming at scale.
