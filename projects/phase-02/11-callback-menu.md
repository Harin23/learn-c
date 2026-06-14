# Project 11: Callback-Based Menu

**Module:** 2.4 — Function Pointers and Error Handling  
**Estimated time:** 4–5 hours

## Description

Build a menu system that dispatches user choices through a table of function pointers. Each action returns an error code consumed by the menu loop.

## File Layout

```
menu/
├── Makefile
├── menu.h
├── menu.c
├── actions.c
├── actions.h
└── main.c
```

## Types (menu.h)

```c
typedef enum {
    MENU_OK = 0,
    MENU_ERR_INVALID,
    MENU_ERR_IO,
    MENU_QUIT
} MenuResult;

typedef MenuResult (*MenuAction)(void);

typedef struct {
    const char *label;
    MenuAction action;
} MenuEntry;
```

## Requirements

### Menu System

- `MenuResult run_menu(const MenuEntry *entries, size_t count)` loops until:
  - User selects quit entry, or
  - An action returns `MENU_QUIT`
- Print numbered options from `label` fields
- Invalid choice prints error, redisplays menu

### Actions (actions.c)

Implement at least four actions:

1. **Greet** — prompt for name, print hello; `MENU_OK`
2. **Counter** — static counter incremented and printed; `MENU_OK`
3. **Fail demo** — returns `MENU_ERR_IO` to test error path
4. **Quit** — returns `MENU_QUIT`

Use error codes consistently; do not call `exit()` from actions.

## Rubric

| Criterion | Points |
|-----------|--------|
| Dispatch via function pointer table | 30 |
| Error codes handled in menu loop | 20 |
| At least 4 actions implemented | 20 |
| Invalid menu input handled | 10 |
| Multi-file with header guards | 10 |
| Valgrind-clean | 10 |
| **Total** | **100** |

## Test Cases

1. Select greet, enter name — greeting printed
2. Select counter twice — count increments
3. Invalid option — error, menu redisplays
4. Quit — program exits 0

## Extension (Optional)

Add `MenuEntry` registration dynamically with your dynamic array from Project 9.
