# Module 1.5 — Basic Debugging and Git Fundamentals

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Use GDB: breakpoints, step, next, print, backtrace
- Read stack traces and locate segfault source lines
- Initialize a Git repo, commit, diff, log, branch, and merge
- Write clear commit messages and maintain a `.gitignore`
- Complete the Phase 1 capstone project

## Prerequisites

- Completed [Module 1.4](../module-01-04-arrays-structs/README.md) exit criteria

## Concepts to Study

1. **Debug symbols** — compile with `-g` for meaningful GDB output
2. **Common crash types** — segmentation fault, stack corruption (surface level)
3. **GDB essentials** — `run`, `break`, `continue`, `step`, `next`, `print`, `bt`, `list`
4. **Reading crash output** — line numbers, function names, backtraces
5. **Git object model** — working tree, staging area (index), commits
6. **Basic Git workflow** — `init`, `add`, `commit`, `log`, `diff`, `branch`, `merge`
7. **Commit messages** — imperative mood, explain why not just what
8. **`.gitignore`** — exclude build artifacts and editor files
9. **Self-review habit** — read your diff before committing

## Hands-On Labs

### Lab 1: Debug the Buggy Calculator

The provided calculator has multiple bugs (logic errors and a crash). Find and fix all bugs using GDB.

Location: [labs/phase-01/buggy_calc/](../../labs/phase-01/buggy_calc/)

Build and debug:

```bash
cd labs/phase-01/buggy_calc
make
gdb ./calc
```

Document each bug: symptom, GDB command that revealed it, fix applied.

### Lab 2: Introduce and Find an Off-by-One Bug

In a small array-processing program, intentionally introduce an off-by-one error. Use GDB to identify the exact line. Fix it. Write a short note on how `bt` and `print` helped.

### Lab 3: Git Workflow

1. Initialize a Git repo for your capstone project
2. Create a branch `feature/csv-load`
3. Implement CSV loading on that branch
4. Merge back to `main` (or `master`)
5. Resolve a deliberate merge conflict if practicing with a partner

Reference: [resources/phase-01.md](../../resources/phase-01.md) — Pro Git chapters 1–3

## Mini-Project

### Phase 1 Capstone — Student Gradebook CLI

See [projects/phase-01/07-gradebook-capstone.md](../../projects/phase-01/07-gradebook-capstone.md).

This is the culminating Phase 1 project. Requirements include multi-file layout, Makefile, CSV persistence, GDB use during development, and a Git history with at least five meaningful commits.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man gdb` | GDB command reference |
| [Debugging with GDB](https://sourceware.org/gdb/current/onlinedocs/gdb/) | Free GNU manual |
| [Pro Git](https://git-scm.com/book/en/v2) | Chapters 1–3 |
| Valgrind | Mentioned here; required in Phase 2.5 |

## Phase 1 Oral Checklist (Self-Assessment)

Answer these without looking at notes:

1. What are the four stages of compilation?
2. What does `-Wall -Wextra` do and why always use it?
3. Why does C pass arguments by value?
4. What terminates a C string?
5. How do you set a breakpoint and inspect a variable in GDB?
6. What is the difference between `git add` and `git commit`?

If you hesitate on more than one question, review the relevant module before starting Phase 2.

## Exit Criteria

Before advancing to Phase 2, confirm:

- [ ] Buggy calculator fixed using GDB in under 30 minutes
- [ ] Capstone builds cleanly with `-Wall -Wextra -std=c11`
- [ ] CSV save/load round-trip works correctly
- [ ] Git history shows at least 5 logical commits with clear messages
- [ ] Project README documents build and run instructions
- [ ] Phase 1 oral checklist completed confidently
- [ ] [Phase 1 exit gate](../README.md#phase-exit-gate) fully satisfied

## Next Phase

[Phase 2 — Memory and Core C](../../phase-02-memory-core-c/) (content coming soon)
