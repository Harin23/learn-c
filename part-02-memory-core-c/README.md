# Part 2 — Memory and Core C

Master pointers, dynamic memory, memory layout, function pointers, error handling, and memory debugging. This part is required before Linux user-space development (Part 4) and data structures (Part 3).

**Estimated time:** 65–80 hours (5 modules × 12–15 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [2.1](module-02-01-pointers/README.md) | Pointers | 12–15 |
| [2.2](module-02-02-dynamic-memory/README.md) | Dynamic Memory Allocation | 12–15 |
| [2.3](module-02-03-stack-heap-layout/README.md) | Memory Layout: Stack vs Heap | 12–15 |
| [2.4](module-02-04-function-pointers-errors/README.md) | Function Pointers and Error Handling | 12–15 |
| [2.5](module-02-05-gdb-valgrind-pitfalls/README.md) | GDB Deep Dive and Common C Pitfalls | 12–15 |

## Prerequisites

Complete the [Part 1 exit gate](../part-01-programming-foundations/README.md#part-exit-gate) before starting.

Install Valgrind (required from Module 2.5):

```bash
sudo apt install valgrind
```

## Part Exit Gate

Do not start Part 3 or Part 4 until you can independently:

- Declare, dereference, and pass pointers; explain the relationship between arrays and pointers
- Allocate and free heap memory correctly with `malloc`/`calloc`/`realloc`/`free`
- Explain stack vs heap storage and why returning pointers to local variables is wrong
- Use function pointers in a callback-based design
- Return structured error codes and handle allocation failures without crashing
- Find memory leaks and invalid accesses with Valgrind
- Fix a deliberately leaky program and explain each Valgrind report line
- Complete the **Part 2 capstone**: stretchy buffer library with tests ([project spec](../projects/part-02/09-dynamic-array.md)) plus Valgrind-clean submission

## Resources

See [resources/part-02.md](../resources/part-02.md) for the canonical reading list.

## Projects in This Part

| # | Project | Module | Spec |
|---|---------|--------|------|
| 8 | Pointer toolkit (swap, reverse) | 2.1 | [08-pointer-toolkit.md](../projects/part-02/08-pointer-toolkit.md) |
| 9 | Dynamic array (stretchy buffer) | 2.2 | [09-dynamic-array.md](../projects/part-02/09-dynamic-array.md) |
| 10 | Stack frame visualizer | 2.3 | [10-stack-visualizer.md](../projects/part-02/10-stack-visualizer.md) |
| 11 | Callback-based menu | 2.4 | [11-callback-menu.md](../projects/part-02/11-callback-menu.md) |
| 12 | Fix memory leaks (Valgrind) | 2.5 | [12-valgrind-fix.md](../projects/part-02/12-valgrind-fix.md) |
