# Project 13: Singly Linked List Toolkit

**Module:** 3.1 — Linked Lists, Stacks, and Queues  
**Estimated time:** 5–6 hours

## Description

Implement a reusable singly linked list library for `int` values with full memory management.

## File Layout

```
list/
├── Makefile
├── list.h
├── list.c
└── main.c
```

## API (list.h)

```c
typedef struct List List;

List *list_create(void);
void  list_destroy(List *list);

int   list_prepend(List *list, int value);   /* 0 ok, -1 alloc fail */
int   list_append(List *list, int value);
int   list_remove(List *list, int value);    /* remove first match; 0 if found */
int   list_contains(const List *list, int value);
size_t list_length(const List *list);
void  list_print(const List *list);            /* format: [1 -> 2 -> 3] */
```

## Requirements

- Empty list prints `[]`
- `list_destroy` frees all nodes and list struct
- No memory leaks (Valgrind-clean)
- `list_remove` removes first occurrence only; returns 0 if removed, -1 if not found

## main.c Demo

```bash
./list_demo
# exercises prepend, append, remove, contains, print
```

## Rubric

| Criterion | Points |
|-----------|--------|
| Prepend/append correct | 25 |
| Remove and contains correct | 25 |
| destroy frees all memory | 20 |
| list_print readable format | 10 |
| Valgrind-clean | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

[labs/part-03/list_starter/](../../labs/part-03/list_starter/)

## Extension (Optional)

Add `list_reverse` in-place O(n) or tail pointer for O(1) append.
