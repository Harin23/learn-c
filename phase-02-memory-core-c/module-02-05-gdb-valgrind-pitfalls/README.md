# Module 2.5 — GDB Deep Dive and Common C Pitfalls

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Use Valgrind to detect memory leaks, invalid reads/writes, and double frees
- Debug heap corruption with GDB and Valgrind together
- Recognize common C pitfalls: UB, buffer overflows, use-after-free, uninitialized memory
- Apply defensive coding habits required for systems programming
- Submit a Valgrind-clean Phase 2 portfolio

## Prerequisites

- Completed [Module 2.4](../module-02-04-function-pointers-errors/README.md) exit criteria
- Valgrind installed: `sudo apt install valgrind`

## Concepts to Study

1. **Undefined behavior (UB)** — compiler may assume it never happens; crashes can be delayed
2. **Buffer overflow** — writing past array bounds; corrupts adjacent memory
3. **Use-after-free** — dereference after `free`; classic security bug
4. **Double free** — calling `free` twice on same pointer
5. **Memory leak** — allocated but never freed; process RSS grows
6. **Uninitialized read** — local or heap garbage used before set
7. **Valgrind Memcheck** — `valgrind --leak-check=full ./program`
8. **GDB advanced** — watchpoints, conditional breakpoints, `print *ptr@10`
9. **Sanitizers preview** — AddressSanitizer (`-fsanitize=address`) as modern alternative

## Hands-On Labs

### Lab 1: Valgrind First Run

Run Valgrind on your dynamic array project from Module 2.2. Fix any leaks or invalid accesses reported.

```bash
valgrind --leak-check=full --show-leak-kinds=all ./your_program
```

### Lab 2: Fix the Leaky Program

The provided program leaks memory, double-frees, and has a use-after-free. Fix all issues until Valgrind reports **0 errors, 0 leaks**.

Location: [labs/phase-02/leaky/](../../labs/phase-02/leaky/)

See [projects/phase-02/12-valgrind-fix.md](../../projects/phase-02/12-valgrind-fix.md) for rubric.

### Lab 3: GDB Watchpoint

Set a hardware watchpoint on a heap variable that gets corrupted. Find the write that overruns a buffer.

Starter discussion in [labs/phase-02/buffer_overflow_demo.c](../../labs/phase-02/buffer_overflow_demo.c)

### Lab 4: Pitfalls Checklist

Write a one-page `PITFALLS.md` in your project directory documenting five pitfalls you encountered in Phase 2 and how you fixed each.

## Mini-Project

**Fix Memory Leaks with Valgrind** — See [projects/phase-02/12-valgrind-fix.md](../../projects/phase-02/12-valgrind-fix.md).

## Phase 2 Integration

Ensure these projects are Valgrind-clean (or document known acceptable allocations):

- Dynamic array (Project 9)
- Callback menu (Project 11)
- Leaky program fix (Project 12)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html) | Official guide |
| `man valgrind` | Command-line options |
| *Effective C* (Robert Seacord) | Pitfalls catalog (optional) |
| GDB: watchpoints, `heap` commands | Deep debugging |

## Phase 2 Oral Checklist (Self-Assessment)

Answer without notes:

1. What is the difference between stack and heap allocation?
2. What happens if you use memory after `free`?
3. How do you pass a pointer so a function can modify caller data?
4. What does Valgrind report for a memory leak?
5. Why is returning a pointer to a local variable wrong?
6. What is a function pointer used for?

## Exit Criteria

Before advancing to Phase 3 or Phase 4, confirm:

- [ ] Leaky program lab: Valgrind reports 0 errors and 0 bytes lost
- [ ] Dynamic array project is Valgrind-clean on test suite
- [ ] You can interpret a Valgrind stack trace to find leak origin
- [ ] GDB watchpoint lab completed
- [ ] `PITFALLS.md` written with five entries
- [ ] Phase 2 oral checklist completed confidently
- [ ] [Phase 2 exit gate](../README.md#phase-exit-gate) fully satisfied

## Next Phase

- [Phase 3 — Data Structures and Algorithms](../../phase-03-data-structures-algorithms/) (coming soon)
- [Phase 4 — Linux User-Space Development](../../phase-04-linux-user-space/) requires Phase 2 exit gate
