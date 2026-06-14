# Module 1.2 — Control Flow and Basic I/O

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Use `if`/`else`, `switch`, `for`, `while`, and `do-while` appropriately
- Handle basic user input validation
- Use logical operators and short-circuit evaluation
- Understand scope of block-local variables
- Read from files using basic stdio functions

## Prerequisites

- Completed [Module 1.1](../module-01-01-first-c-program/README.md) exit criteria

## Concepts to Study

1. **Boolean expressions in C** — zero is false, non-zero is true; no native `bool` until C99 (`stdbool.h`)
2. **Conditional statements** — `if`, `else if`, `else`; dangling else pitfalls
3. **`switch` statements** — `case`, `break`, `default`; fall-through behavior
4. **Loops** — `for`, `while`, `do-while`; when to use each
5. **`break` and `continue`** — exiting loops early vs skipping iterations
6. **Scope** — block-local variables; shadowing (avoid it)
7. **Basic file I/O** — `fopen`, `fclose`, `fprintf`, `fgets`, `feof`, `ferror`
8. **Error handling pattern** — always check return values from I/O functions

## Hands-On Labs

### Lab 1: FizzBuzz Three Ways

Implement FizzBuzz (1–100: print "Fizz" for multiples of 3, "Buzz" for 5, "FizzBuzz" for both, else the number) using:
1. A `for` loop with `if`/`else`
2. A `while` loop
3. A `switch`-based approach using modulo (discuss readability trade-offs)

### Lab 2: Input Sanitizer

Write a function `read_int_in_range(int min, int max, int *out)` that repeatedly prompts until the user enters a valid integer within `[min, max]`. Clear the input buffer on invalid input.

**Security habit:** Never use `scanf("%s", buf)` without a width limit. Prefer `scanf("%d", &n)` for integers or `fgets` + `strtol` for robust parsing.

### Lab 3: Line Counter

Write a program that counts lines in a text file passed as a command-line argument. Use `fgets` in a loop. Compare your count to `wc -l` on a test file.

Starter: [labs/phase-01/line_counter_starter.c](../../labs/phase-01/line_counter_starter.c)

## Mini-Projects

### Guess-the-Number Game

See [projects/phase-01/02-guess-the-number.md](../../projects/phase-01/02-guess-the-number.md).

### Grade Calculator

See [projects/phase-01/03-grade-calculator.md](../../projects/phase-01/03-grade-calculator.md).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapters 1–3 | Control flow and basic I/O |
| `man 3 fopen` | File open modes |
| `man 3 fgets` | Safe line reading |

## Exit Criteria

Before advancing to Module 1.3, confirm:

- [ ] All three FizzBuzz implementations produce identical output
- [ ] Input sanitizer handles garbage input without infinite loops
- [ ] Line counter matches `wc -l` on test files
- [ ] Guess-the-number and grade calculator projects are complete
- [ ] No unbounded `scanf` into char buffers anywhere in your code
- [ ] Grade calculator handles invalid input without crashing

## Next Module

[Module 1.3 — Functions and Program Organization](../module-01-03-functions/README.md)
