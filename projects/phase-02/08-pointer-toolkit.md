# Project 8: Pointer Toolkit

**Module:** 2.1 — Pointers  
**Estimated time:** 3–4 hours

## Description

Build a small library of pointer-based utilities demonstrating pass-by-pointer, pointer arithmetic, and string manipulation.

## File Layout

```
pointer_toolkit/
├── Makefile
├── pointer_toolkit.h
├── pointer_toolkit.c
└── main.c
```

## API (pointer_toolkit.h)

Implement:

```c
void swap_int(int *a, int *b);
void reverse_string(char *s);           /* in place, pointer-based */
size_t str_length(const char *s);       /* no strlen — walk with pointer */
int array_sum(const int *arr, size_t n);
int array_max(const int *arr, size_t n);
```

### Requirements

- `reverse_string`: empty string is no-op; single char is no-op
- `str_length`: return 0 for `NULL` (document this behavior)
- `array_sum` / `array_max`: assume `n > 0`; use pointer walk (minimal subscripting)

## main.c

Demo program that:

1. Swaps two integers and prints result
2. Reverses `"hello"` in a mutable buffer
3. Prints length of `"linux"`
4. Sums and finds max of `{3, -1, 7, 2}`

## Rubric

| Criterion | Points |
|-----------|--------|
| `swap_int` modifies caller variables | 20 |
| `reverse_string` correct (pointer impl) | 25 |
| `str_length` correct without strlen | 15 |
| `array_sum` and `array_max` via pointer walk | 20 |
| Zero warnings, Makefile with clean target | 10 |
| Handles empty string in reverse | 10 |
| **Total** | **100** |

## Test Cases

1. `swap_int(&a, &b)` with a=1, b=2 → a=2, b=1
2. Reverse `"abcd"` → `"dcba"`
3. Reverse `""` → no crash
4. `str_length("hello")` → 5
5. `array_max` of `{3,-1,7,2}` → 7

## Extension (Optional)

Add `void copy_string(char *dst, size_t dst_size, const char *src)` with bounds checking.
