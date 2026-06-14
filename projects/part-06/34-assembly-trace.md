# Project 34: Assembly and Register Trace

**Module:** 6.1 — CPU Architecture and Instruction Execution  
**Estimated time:** 5–6 hours

## Description

Analyze compiler-generated assembly for a small multi-function C program. Document register use, stack frames, and control flow with GDB evidence.

## Program (provided)

Use [labs/part-06/add_regs.c](../../labs/part-06/add_regs.c) or equivalent with:

- `int add(int a, int b)`
- `int factorial(int n)` (recursive)
- `main` calling both

Compile: `gcc -g -O0 -fno-omit-frame-pointer -Wall -Wextra -std=c11`

## Deliverables

1. `TRACE.md` containing:
   - Snippet of `add` assembly (AT&T or Intel) with annotations
   - Table: which register holds each argument at call to `add`
   - Stack diagram at deepest `factorial` recursion (one frame)
   - GDB session transcript: `break add`, `info registers`, `stepi` × 5

2. Answers (short paragraphs):
   - Purpose of `%rbp` in frame pointer mode
   - What `call` and `ret` do to `%rsp` and `%rip`

## Rubric

| Criterion | Points |
|-----------|--------|
| Correct argument register identification | 25 |
| Stack frame diagram for one function | 25 |
| GDB transcript with register dumps | 25 |
| Written answers on call/ret | 15 |
| Uses `-O0` and documents why | 10 |
| **Total** | **100** |

## Commands Reference

```bash
gcc -S -O0 -fno-omit-frame-pointer add_regs.c
objdump -d -M intel add_regs
gdb ./add_regs
```

## Extension (Optional)

Repeat with `-O2` and note optimized-out frame pointer.
