# Module 2.2 — Dynamic Memory Allocation

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Allocate memory with `malloc`, `calloc`, and `realloc`
- Free memory with `free` and avoid double-free
- Check allocation failures and handle them gracefully
- Build resizable data structures on the heap
- Understand ownership: who allocates must free (or transfer ownership explicitly)

## Prerequisites

- Completed [Module 2.1](../module-02-01-pointers/README.md) exit criteria

## Concepts to Study

1. **Stack vs heap preview** — automatic variables vs explicit allocation (deep dive in 2.3)
2. **`malloc(size)`** — uninitialized bytes; returns `NULL` on failure
3. **`calloc(n, size)`** — zero-initialized; useful for arrays
4. **`realloc(ptr, size)`** — resize; may move block; handle `NULL` return carefully
5. **`free(ptr)`** — release; `free(NULL)` is safe; never use pointer after free
6. **Ownership rules** — document who frees what in function comments
7. **`size_t`** — unsigned type for sizes and counts
8. **Common bugs** — memory leak, double free, use-after-free, off-by-one past allocation

## Hands-On Labs

### Lab 1: Manual Dynamic Array

Allocate an `int` array of size `n` from user input. Read `n` integers, print them, free memory.

Check `malloc` return value before use.

### Lab 2: Grow-on-Demand

Start with capacity 4. Read integers until EOF, doubling capacity with `realloc` when full. Print count and sum. Free at end.

Starter: [labs/part-02/grow_array_starter.c](../../labs/part-02/grow_array_starter.c)

### Lab 3: strdup Pattern

Implement a function `char *str_dup(const char *s)` that allocates and copies a string. Caller frees result.

### Lab 4: Allocation Failure Handling

Simulate failure by requesting an absurdly large block (`SIZE_MAX / 2`). Verify your code prints an error and exits cleanly without crashing.

## Mini-Project

**Dynamic Array (Stretchy Buffer)** — See [projects/part-02/09-dynamic-array.md](../../projects/part-02/09-dynamic-array.md).

This project carries into Part 3 as a foundation for linked lists and other structures.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapter 5 (malloc section) | If present in your edition; else `man 3 malloc` |
| `man 3 malloc`, `man 3 free`, `man 3 realloc` | Primary reference |
| `man 3 calloc` | Zero-init allocation |

## Exit Criteria

Before advancing to Module 2.3, confirm:

- [ ] Every `malloc`/`calloc`/`realloc` has a matching `free` on all code paths
- [ ] Allocation failures handled without dereferencing NULL
- [ ] Grow-on-demand lab passes stress test (1000+ integers)
- [ ] Dynamic array project passes rubric (API implemented, no leaks on happy path)
- [ ] You can explain why `realloc` return value must be assigned carefully

## Next Module

[Module 2.3 — Memory Layout: Stack vs Heap](../module-02-03-stack-heap-layout/README.md)
