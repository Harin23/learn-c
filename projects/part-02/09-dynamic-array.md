# Project 9: Dynamic Array (Stretchy Buffer)

**Module:** 2.2 — Dynamic Memory Allocation  
**Estimated time:** 5–6 hours

## Description

Implement a generic-ish dynamic array of `int` values that grows automatically. This structure is reused throughout Part 3.

## File Layout

```
darray/
├── Makefile
├── darray.h
├── darray.c
├── main.c
└── test_main.c    /* optional simple tests */
```

## API (darray.h)

```c
typedef struct {
    int *data;
    size_t size;      /* number of elements in use */
    size_t capacity;  /* allocated slots */
} IntArray;

void ia_init(IntArray *a);
void ia_free(IntArray *a);
int  ia_append(IntArray *a, int value);   /* 0 ok, -1 on alloc failure */
int  ia_get(const IntArray *a, size_t index, int *out);  /* 0 ok, -1 bad index */
size_t ia_length(const IntArray *a);
```

### Behavior

- `ia_init`: empty array, no allocation yet (or initial capacity 0)
- `ia_append`: double capacity when full (start at 4 or 8); return -1 if `realloc` fails
- `ia_get`: bounds-checked read
- `ia_free`: release memory; safe to call on zeroed struct; leave in valid empty state

## main.c

Read integers from stdin until EOF, append each, print all elements and count.

```bash
echo "1 2 3 4 5" | ./darray
# 1 2 3 4 5 (count: 5)
```

## Rubric

| Criterion | Points |
|-----------|--------|
| Append with geometric growth | 25 |
| All allocation failures handled | 20 |
| `ia_get` bounds checking | 15 |
| `ia_free` idempotent / no double free | 15 |
| No memory leaks on happy path (Valgrind) | 15 |
| Zero compiler warnings | 10 |
| **Total** | **100** |

## Test Cases

1. Append 1000 values — all retrievable
2. `ia_get` out of range returns -1
3. Valgrind: `echo "1 2 3" | ./darray` — 0 leaks
4. `ia_free` then `ia_init` again — works

## Starter

Optional: [labs/part-02/darray_starter/](../../labs/part-02/darray_starter/)

## Extension (Optional)

Add `ia_pop`, `ia_reserve`, or `ia_sort` using `qsort`.
