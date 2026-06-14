# Module 1.3 — Functions and Program Organization

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Write functions with prototypes, parameters, and return values
- Split code across `.c` and `.h` files
- Understand pass-by-value semantics
- Use `static` functions for internal linkage
- Write a simple Makefile with `all` and `clean` targets

## Prerequisites

- Completed [Module 1.2](../module-01-02-control-flow/README.md) exit criteria

## Concepts to Study

1. **Function prototypes vs definitions** — declare before use; define once
2. **Header guards** — `#ifndef`, `#define`, `#endif` (or `#pragma once`)
3. **Translation units** — each `.c` file compiles independently, links together
4. **Linkage** — `extern` for shared globals (discouraged); `static` for file-local
5. **Pass-by-value** — C copies argument values; changing parameters does not affect caller
6. **Return values** — use return codes for success/failure where appropriate
7. **Makefile basics** — `CC`, `CFLAGS`, targets, dependencies, `clean`

## Hands-On Labs

### Lab 1: Extract Math Helpers

Take a single-file program with inline math functions and split it into:
- `math_utils.h` — prototypes and header guard
- `math_utils.c` — implementations (mark helpers `static` if not exported)
- `main.c` — calls the public API

Build manually:

```bash
gcc -Wall -Wextra -std=c11 -c math_utils.c -o math_utils.o
gcc -Wall -Wextra -std=c11 -c main.c -o main.o
gcc math_utils.o main.o -o math_demo
```

Starter: [labs/phase-01/math_utils_starter/](../../labs/phase-01/math_utils_starter/)

### Lab 2: Makefile Build

Add a `Makefile` to the math utils project with:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
```

Targets: `all` (build binary), `clean` (remove objects and binary).

### Lab 3: Pass-by-Value with GDB

Write a `swap(int a, int b)` function that fails to swap (pass-by-value). Debug with GDB, observe parameter values before and after. This prepares you for pointers in Phase 2.

## Mini-Project

**Statistics Library** — See [projects/phase-01/04-statistics-library.md](../../projects/phase-01/04-statistics-library.md).

Implement `min`, `max`, `mean`, and `median` over an `int` array in a multi-file project with a Makefile.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapters 1 and 4 | Functions |
| `man gcc` | Compiler options |
| [GNU Make Manual — Introduction](https://www.gnu.org/software/make/manual/html_node/Introduction.html) | Makefile basics |

## Exit Criteria

Before advancing to Module 1.4, confirm:

- [ ] Multi-file project builds via Makefile without warnings
- [ ] Headers have include guards; no duplicate symbol errors at link time
- [ ] You can explain the difference between a declaration and a definition
- [ ] You can explain why `swap(int a, int b)` does not swap caller variables
- [ ] Statistics library project passes its rubric

## Next Module

[Module 1.4 — Arrays, Strings, Structs, and Enums](../module-01-04-arrays-structs/README.md)
