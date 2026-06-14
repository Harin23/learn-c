# Module 2.1 — Pointers

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain what a pointer is and why C uses addresses
- Declare pointers, take addresses with `&`, and dereference with `*`
- Pass pointers to functions to modify caller data
- Use pointer arithmetic on arrays and strings
- Distinguish between a pointer and what it points to
- Avoid null pointer dereferences and uninitialized pointers

## Prerequisites

- Completed [Phase 1 exit gate](../../phase-01-programming-foundations/README.md#phase-exit-gate)
- Comfortable with arrays, strings, and functions from Phase 1

## Concepts to Study

1. **Memory addresses** — variables live at addresses; `&x` yields the address of `x`
2. **Pointer declaration** — `int *p;` means `p` can point to an `int`
3. **Dereference** — `*p` reads or writes the value at the address in `p`
4. **Null pointer** — `NULL` means "points nowhere"; always check before use
5. **Pass-by-value vs pass-by-pointer** — why Phase 1 `swap` failed; fix with `int *`
6. **Array decay** — array name converts to pointer to first element in most expressions
7. **Pointer arithmetic** — `p + 1` moves by `sizeof(*p)` bytes
8. **Const and pointers** — `const int *p` vs `int *const p` (read-only vs fixed address)
9. **String as char pointer** — `char *s = "hello"` vs `char buf[] = "hello"`

## Hands-On Labs

### Lab 1: Address and Value Tracing

Write a program that declares `int x = 42` and `int *p = &x`. Print:

- Value of `x`
- Address of `x` with `%p` and `(void *)&x`
- Value of `p` (should match address of `x`)
- Value of `*p` (should be 42)

Starter: [labs/phase-02/pointer_basics_starter.c](../../labs/phase-02/pointer_basics_starter.c)

### Lab 2: Fix the Swap

Implement `void swap(int *a, int *b)` that exchanges values in caller variables. Verify with GDB that caller variables change.

Starter: [labs/phase-02/swap_starter.c](../../labs/phase-02/swap_starter.c)

### Lab 3: String Reverse with Pointers

Re-implement string reverse using pointer notation instead of array indices. Handle empty strings.

### Lab 4: Array Sum via Pointer Walk

Write `int array_sum(const int *arr, size_t n)` that walks from `arr` to `arr + n` without subscript notation.

## Mini-Project

**Pointer Toolkit** — See [projects/phase-02/08-pointer-toolkit.md](../../projects/phase-02/08-pointer-toolkit.md).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapter 5 | Pointers and arrays |
| `man 7 feature_test_macros` | Skim for later POSIX work |
| [CS50 — Pointers](https://cs50.harvard.edu/x/) | Free supplement |

## Exit Criteria

Before advancing to Module 2.2, confirm:

- [ ] Can draw a diagram showing `x`, `&x`, `p`, and `*p` for a simple example
- [ ] `swap` works correctly via pointers
- [ ] String reverse works with pointer implementation
- [ ] No crashes on empty string input
- [ ] Pointer toolkit project passes its rubric
- [ ] You never dereference uninitialized or NULL pointers without checking

## Next Module

[Module 2.2 — Dynamic Memory Allocation](../module-02-02-dynamic-memory/README.md)
