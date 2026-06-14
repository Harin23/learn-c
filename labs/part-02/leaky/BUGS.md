# Leaky Program — Instructor / Self-Check Reference

**Do not read until you have run Valgrind and attempted fixes.**

## Bug 1: Memory leak in `process_orphan`

**Location:** `process_orphan`  
**Symptom:** Valgrind reports 64 bytes lost from `malloc(64)`  
**Fix:** `free(temp)` before return, or remove function if unused.

## Bug 2: Double free in `name_list_free`

**Location:** `name_list_free`, loop over names  
**Symptom:** Valgrind `Invalid free()` / double free on first name  
**Fix:** Remove the extra `free(list->names[i])` when `i == 0`.

## Bug 3: Use-after-free in main loop

**Location:** `main`, after `name_list_add`  
**Symptom:** Invalid read when printing names; garbage or crash  
**Fix:** Remove `free(line)` after add — `name_list` owns the pointer. Free in `name_list_free` only.

## Correct ownership model

- `read_line` returns heap allocation → transferred to `name_list_add`
- `name_list_free` frees each name and the `names` array
- No other `free` of those pointers

## Sample clean Valgrind output

```
ERROR SUMMARY: 0 errors from 0 contexts
All heap blocks were freed -- no leaks are possible
```

## Fixed main loop (reference)

```c
while (list.count < MAX_NAMES && (line = read_line()) != NULL) {
    if (name_list_add(&list, line) != 0) {
        free(line);
        break;
    }
}
```
