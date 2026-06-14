# Module 2.3 — Memory Layout: Stack vs Heap

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain where automatic, static, and heap-allocated variables live
- Describe stack frames and why local variable addresses change between calls
- Identify dangling pointers from returning addresses of locals
- Compare addresses of stack vs heap variables
- Read a simple memory layout diagram for a running program

## Prerequisites

- Completed [Module 2.2](../module-02-02-dynamic-memory/README.md) exit criteria

## Concepts to Study

1. **Process address space** — code (text), data, BSS, heap, stack (high-level model)
2. **Stack** — function calls push frames; locals typically on stack; LIFO
3. **Heap** — dynamic allocation; lifetime until `free`
4. **Static storage** — global and `static` variables; program lifetime
5. **Dangling pointers** — `return &local;` is undefined behavior
6. **Address printing** — `%p` with `(void *)` cast; observe relative ordering
7. **Stack overflow** — unbounded recursion or huge stack arrays (preview)
8. **Alignment and padding** — structs may have gaps (ties to Phase 6)

## Hands-On Labs

### Lab 1: Where Do Variables Live?

Write a program with:

- A global variable
- A function-local automatic variable
- A `static` local variable
- A heap variable from `malloc`

Print addresses of each. Run multiple times — which addresses change?

Starter: [labs/phase-02/memory_addresses_starter.c](../../labs/phase-02/memory_addresses_starter.c)

### Lab 2: Dangling Pointer Demonstration

Write a function that incorrectly returns `int *get_dangling(void)` returning address of a local. Call it, print `*result` — observe garbage or crash. Fix by returning via parameter or heap allocation.

**Do not rely on "it worked once" — this is undefined behavior.**

### Lab 3: Stack Depth

Write recursive `void depth(int n)` that prints address of a local `int frame`. Observe address direction as depth increases.

### Lab 4: Frame Layout Sketch

Pick a two-function call chain from your code. Draw on paper: caller frame, callee frame, where parameters and return address live. Compare to GDB `info frame` output.

## Mini-Project

**Stack Frame Visualizer** — See [projects/phase-02/10-stack-visualizer.md](../../projects/phase-02/10-stack-visualizer.md).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *Computer Systems: A Programmer's Perspective* (CS:APP), Ch. 3 | Stack frames (optional but excellent) |
| GDB: `info frame`, `info locals`, `backtrace` | Hands-on |
| Phase 6 preview — virtual memory | Skim roadmap only |

## Exit Criteria

Before advancing to Module 2.4, confirm:

- [ ] Can explain why returning a pointer to a local variable is wrong
- [ ] Can identify stack vs heap allocation in a given code snippet
- [ ] Stack visualizer project prints meaningful frame address progression
- [ ] Used GDB `bt` and `info locals` on recursive function at least once
- [ ] You can sketch a stack with two nested function calls

## Next Module

[Module 2.4 — Function Pointers and Error Handling](../module-02-04-function-pointers-errors/README.md)
