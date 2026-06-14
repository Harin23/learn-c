# Module 1.1 — First C Program, Variables, and Types

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Set up an Ubuntu C toolchain and editor workflow
- Understand `main`, compilation, and running binaries
- Declare and use integer, floating, and character types
- Use `printf`/`scanf`, format specifiers, and basic expressions
- Read compiler warnings and fix them

## Prerequisites

- Comfortable using the Linux terminal (`cd`, `ls`, `mkdir`, a text editor)
- Completed [environment setup](../../docs/environment-setup.md)

## Concepts to Study

1. **What C is** — A low-level systems language; foundation of Linux, kernels, and drivers
2. **Compilation pipeline** — preprocess → compile → assemble → link
3. **Basic program structure** — `#include`, `stdio.h`, `int main(void)`, `return 0`
4. **Types** — `char`, `short`, `int`, `long`, `float`, `double`, `_Bool`
5. **Literals and operators** — arithmetic, comparison, logical; precedence rules
6. **Implicit promotion** — how smaller types promote in expressions
7. **`const`** — values that must not change after initialization
8. **Coding style** — consistent naming; note that the Linux kernel uses tabs (you may use spaces in Phase 1)

## Hands-On Labs

### Lab 1: Toolchain Verification

1. Run `scripts/verify-phase-01.sh` from the repository root.
2. Compile the provided hello program:

   ```bash
   cd labs/phase-01
   gcc -Wall -Wextra -std=c11 -o hello hello.c
   ./hello
   ```

3. Observe that `-Wall -Wextra` produces no warnings on clean code.

### Lab 2: Format Specifier Experiments

Create `format_experiment.c` that prints an `int` with `%f` and a `double` with `%d`. Compile with warnings enabled. Run under GDB if it crashes. Write one paragraph explaining why mismatched specifiers are dangerous.

### Lab 3: Type Sizes with `sizeof`

Write a program that prints `sizeof` for every basic type on your machine. Compare `int` vs `long`. This foreshadows why fixed-width types (`stdint.h`) appear later in systems code.

### Lab 4: Temperature Converter

Write a program that converts Celsius to Fahrenheit and back. Use `double` for input. Formula: `F = C * 9.0 / 5.0 + 32.0`.

## Mini-Project

**Unit Converter CLI** — See [projects/phase-01/01-unit-converter.md](../../projects/phase-01/01-unit-converter.md).

Build a menu-driven program supporting:
- Length (meters ↔ feet)
- Mass (kilograms ↔ pounds)
- Temperature (Celsius ↔ Fahrenheit)

Handle invalid menu choices and non-numeric input gracefully (re-prompt, do not crash).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| *The C Programming Language* (Kernighan & Ritchie), Chapter 1 | Primary text |
| `man 3 printf` | Format specifiers |
| `man 3 scanf` | Input parsing |
| [CS50 C Reference](https://cs50.harvard.edu/x/) | Free online supplement |

## Exit Criteria

Before advancing to Module 1.2, confirm:

- [ ] All lab programs compile without warnings using `-Wall -Wextra -std=c11`
- [ ] You can explain the purpose of `#include`, `int main`, and `return 0`
- [ ] You can describe the four compilation stages at a high level
- [ ] Unit converter mini-project is complete and handles invalid input
- [ ] You always compile with warnings enabled (make this a habit)

## Next Module

[Module 1.2 — Control Flow and Basic I/O](../module-01-02-control-flow/README.md)
