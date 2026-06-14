# Project 12: Fix Memory Leaks with Valgrind

**Module:** 2.5 — GDB Deep Dive and Common C Pitfalls  
**Estimated time:** 4–5 hours

## Description

Fix all memory errors in the provided leaky program. Submit a Valgrind-clean solution with a written report.

## Starting Point

Location: [labs/part-02/leaky/](../../labs/part-02/leaky/)

```bash
cd labs/part-02/leaky
make
valgrind --leak-check=full --show-leak-kinds=all ./leaky
```

Initial Valgrind run should report multiple errors (leaks, invalid read/write, double free, or use-after-free).

## Tasks

1. Run Valgrind and record initial error summary
2. Fix bugs one category at a time; re-run Valgrind after each fix
3. Use GDB where Valgrind stack traces are insufficient
4. Write `REPORT.md` documenting:
   - Each bug type found
   - Valgrind message that identified it
   - Fix applied
   - Final Valgrind summary (must be clean)

## Success Criteria

Final run must show:

```
ERROR SUMMARY: 0 errors from 0 contexts
All heap blocks were freed -- no leaks are possible
```

(or equivalent zero-leak output for your Valgrind version)

## Rubric

| Criterion | Points |
|-----------|--------|
| All Valgrind errors eliminated | 40 |
| All memory leaks eliminated | 25 |
| REPORT.md with before/after analysis | 20 |
| Program still produces correct output | 10 |
| Zero compiler warnings | 5 |
| **Total** | **100** |

## Correct Program Behavior

After fixes, running `./leaky` should:

1. Read three lines of input (names)
2. Print greeting for each name
3. Print summary count
4. Exit 0

Test input:

```
Alice
Bob
Carol
```

Expected output (exact wording may vary):

```
Hello, Alice
Hello, Bob
Hello, Carol
Processed 3 names.
```

## GDB Requirement

Document at least one bug fixed with GDB assistance (breakpoint or watchpoint) in `REPORT.md`.

## Extension (Optional)

Run with AddressSanitizer: `gcc -fsanitize=address -g ...` and compare output to Valgrind.
