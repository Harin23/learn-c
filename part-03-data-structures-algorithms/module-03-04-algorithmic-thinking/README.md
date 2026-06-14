# Module 3.4 — Algorithmic Thinking

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Break problems into clear algorithmic steps before coding
- Recognize common patterns: search, sort, divide-and-conquer, two-pointer
- Implement binary search on sorted arrays
- Implement classic sorting algorithms and understand their complexity
- Use recursion and iteration interchangeably where appropriate
- Trace algorithm execution on small inputs by hand

## Prerequisites

- Completed [Module 3.3](../module-03-03-trees/README.md) exit criteria

## Concepts to Study

1. **Problem decomposition** — inputs, outputs, invariants, edge cases
2. **Linear search** — O(n); baseline for unsorted data
3. **Binary search** — O(log n) on sorted array; off-by-one pitfalls
4. **Sorting algorithms** — bubble, insertion, merge, quicksort (implement subset)
5. **Divide and conquer** — merge sort pattern; recursion tree
6. **Two-pointer technique** — sorted array pairs, palindrome checks
7. **Greedy preview** — local optimal choice; proof often needed later
8. **Correctness** — loop invariants; test edge cases (empty, one element)

## Hands-On Labs

### Lab 1: Binary Search

Implement iterative `binary_search(const int *arr, size_t n, int target)` returning index or -1.

Starter: [labs/part-03/binary_search_starter.c](../../labs/part-03/binary_search_starter.c)

### Lab 2: Insertion Sort

Implement in-place insertion sort. Trace on paper for `{5, 2, 4, 1}`.

Starter: [labs/part-03/insertion_sort_starter.c](../../labs/part-03/insertion_sort_starter.c)

### Lab 3: Merge Sort

Implement merge sort on `int` arrays using temporary buffer. Compare to insertion sort on 10,000 random ints (informal timing).

Starter: [labs/part-03/merge_sort_starter/](../../labs/part-03/merge_sort_starter/)

### Lab 4: Algorithm Design Exercise

Given a sorted list of timestamps and a query range `[t0, t1]`, find all entries in range. Design O(log n + k) approach using binary search to find bounds.

Write pseudocode before implementing.

## Module Integration

This module has no standalone mini-project. Skills feed directly into [Module 3.5](../module-03-05-performance-analysis/README.md) and [Project 18](../../projects/part-03/18-sort-benchmark.md).

Optional practice: re-implement search on your BST vs sorted array and compare steps for the same keys.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| CLRS, Ch. 2–4 | Insertion sort, merge sort, binary search |
| *Problem Solving with Algorithms and Data Structures* (Bradley, Miller) | Free online |
| LeetCode / Advent of Code (easy) | Optional extra practice |

## Exit Criteria

Before advancing to Module 3.5, confirm:

- [ ] Binary search passes all test cases including not-found
- [ ] Insertion sort and merge sort produce correctly sorted output
- [ ] You can write Big-O for binary search, insertion sort, merge sort
- [ ] You traced merge sort recursion on a 4-element array by hand
- [ ] Range query lab pseudocode written and reviewed

## Next Module

[Module 3.5 — Performance Analysis](../module-03-05-performance-analysis/README.md)
