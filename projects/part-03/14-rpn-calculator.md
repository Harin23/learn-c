# Project 14: RPN Calculator

**Module:** 3.1 — Linked Lists, Stacks, and Queues  
**Estimated time:** 4–5 hours

## Description

Build a Reverse Polish Notation (RPN) calculator using a stack ADT. Supports `+`, `-`, `*`, `/` on integers.

## File Layout

```
rpn/
├── Makefile
├── stack.h
├── stack.c
└── main.c
```

## Stack API (stack.h)

```c
typedef struct Stack Stack;

Stack *stack_create(void);
void   stack_destroy(Stack *s);
int    stack_push(Stack *s, int value);
int    stack_pop(Stack *s, int *out);   /* 0 ok, -1 empty */
int    stack_peek(const Stack *s, int *out);
int    stack_is_empty(const Stack *s);
```

Use linked-list or dynamic-array backend (your choice).

## Input

Read tokens from stdin one per line or space-separated:

```
3
4
+
2
*
```

Or single line: `3 4 + 2 *`

Result printed once input ends (EOF or blank line after tokens).

## Operators

- Binary operators pop two values (second popped is left operand)
- `3 4 +` → 7
- `3 4 + 2 *` → 14
- Division truncates toward zero (C `/` on ints)
- Error on divide by zero or insufficient stack — print message, exit 1

## Rubric

| Criterion | Points |
|-----------|--------|
| Stack ADT correct | 25 |
| Four operators correct | 30 |
| Operand order correct for `-` and `/` | 20 |
| Error handling (empty stack, div zero) | 15 |
| Valgrind-clean | 10 |
| **Total** | **100** |

## Test Cases

| Input | Result |
|-------|--------|
| `3 4 +` | 7 |
| `3 4 + 2 *` | 14 |
| `5 1 2 + 4 * + 3 -` | 14 |
| `4 0 /` | error |

## Starter

[labs/part-03/stack_starter/](../../labs/part-03/stack_starter/)

## Extension (Optional)

Support floating point with `double` stack.
