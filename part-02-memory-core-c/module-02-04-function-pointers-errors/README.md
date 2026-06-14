# Module 2.4 — Function Pointers and Error Handling

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Declare, assign, and call functions through pointers
- Use function pointers for callbacks and dispatch tables
- Design functions that return error codes via return value or out-parameters
- Handle errors consistently without silent failures
- Read simple uses of function pointers in open-source C code

## Prerequisites

- Completed [Module 2.3](../module-02-03-stack-heap-layout/README.md) exit criteria

## Concepts to Study

1. **Function pointer syntax** — `int (*cmp)(const void *, const void *);`
2. **Typedef for clarity** — `typedef int (*BinaryOp)(int, int);`
3. **Callback pattern** — pass behavior into generic code (sort, iterate, menu)
4. **Dispatch table** — array of function pointers indexed by enum
5. **Error codes** — return `0` success, negative or positive codes for errors
6. **`errno`** — preview; set by some library calls; check after failures
7. **Out-parameters** — `int parse_int(const char *s, int *out);`
8. **Fail fast vs recover** — when to abort vs retry vs report to user
9. **Assertions vs errors** — `assert` for programmer bugs; return codes for runtime input

## Hands-On Labs

### Lab 1: Calculator with Function Pointers

Define `typedef int (*BinOp)(int, int)` and implement `add`, `sub`, `mul`, `safe_div`. Select operation via function pointer array.

Starter: [labs/part-02/fn_ptr_calc_starter.c](../../labs/part-02/fn_ptr_calc_starter.c)

### Lab 2: Apply to Array

Write `void map_int(int *arr, size_t n, int (*fn)(int))` that applies `fn` to each element in place.

### Lab 3: Error Code API

Implement:

```c
typedef enum {
    PARSE_OK = 0,
    PARSE_EMPTY,
    PARSE_INVALID,
    PARSE_OVERFLOW
} ParseResult;

ParseResult parse_positive_int(const char *s, int *out);
```

Test with valid input, empty string, `"abc"`, and out-of-range values.

### Lab 4: qsort Preview

Read `man 3 qsort`. Sort an `int` array using `qsort` and a compare function `int_cmp`. Understand why the compare function signature uses `const void *`.

## Mini-Project

**Callback-Based Menu** — See [projects/part-02/11-callback-menu.md](../../projects/part-02/11-callback-menu.md).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Section on function pointers | If in your edition |
| `man 3 qsort` | Real-world callback API |
| Linux kernel function pointers | Skim `include/linux/` patterns in Part 7 |

## Exit Criteria

Before advancing to Module 2.5, confirm:

- [ ] Function pointer calculator dispatches correctly
- [ ] `map_int` works with at least two different callback functions
- [ ] Parse API returns distinct codes for distinct failures
- [ ] Callback menu project passes rubric
- [ ] You can read `typedef ... (*name)(...)` without confusion

## Next Module

[Module 2.5 — GDB Deep Dive and Common C Pitfalls](../module-02-05-gdb-valgrind-pitfalls/README.md)
