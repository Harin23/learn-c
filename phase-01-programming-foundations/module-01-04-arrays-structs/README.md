# Module 1.4 — Arrays, Strings, Structs, and Enums

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Use fixed arrays and C strings (`char[]`, null terminator)
- Perform bounded string operations safely
- Define and use `struct` and `enum`
- Combine structs with arrays to build small in-memory databases
- Parse simple structured text (CSV lines)

## Prerequisites

- Completed [Module 1.3](../module-01-03-functions/README.md) exit criteria

## Concepts to Study

1. **Fixed arrays** — declaration, initialization, bounds; no runtime bounds checking in C
2. **Array decay** — arrays pass to functions as pointers (deep dive in Phase 2.1)
3. **C strings** — `char buf[N]` with null terminator `'\0'`; string literals are read-only
4. **Safe string operations** — `strncpy`, `snprintf`, `strlen`; never use `gets`
5. **`string.h`** — common functions and their pitfalls (e.g., `strncpy` may not null-terminate)
6. **`struct`** — grouping related data; dot vs arrow operator preview
7. **Struct layout** — padding exists (details in Phase 6); keep structs simple for now
8. **`enum`** — readable named constants; underlying integer type
9. **`typedef`** — optional alias for struct types (common in real codebases)

## Hands-On Labs

### Lab 1: Reverse String In-Place

Write `reverse_string(char *s)` using index-based swapping only (no pointer arithmetic required). Test with odd- and even-length strings.

Starter: [labs/phase-01/reverse_string_starter.c](../../labs/phase-01/reverse_string_starter.c)

### Lab 2: CSV Line Parser

Parse a line like `Alice,28,Engineer` into a `Person` struct with `name`, `age`, and `title` fields. Handle fields with a fixed maximum name length.

Test data: [labs/phase-01/sample_contacts.csv](../../labs/phase-01/sample_contacts.csv)

### Lab 3: Enum State Machine

Implement a traffic light or bank transaction state machine using `enum` for states and `switch` for transitions. Log each state change to stdout.

## Mini-Projects

### Contact Card Manager

See [projects/phase-01/05-contact-card-manager.md](../../projects/phase-01/05-contact-card-manager.md).

### Word Counter CLI

See [projects/phase-01/06-word-counter.md](../../projects/phase-01/06-word-counter.md).

## Recommended Resources

| Resource | Notes |
|----------|-------|
| K&R, Chapter 5 (partial) and Chapter 6 | Pointers preview, structs |
| `man 3 string` | String function reference |
| `man 7 signal` | Skim for Phase 4 context |

## Exit Criteria

Before advancing to Module 1.5, confirm:

- [ ] No buffer overflows in submitted string code (use bounded copies)
- [ ] Contact manager uses structs and enums correctly
- [ ] Word counter output matches `wc` on provided test files
- [ ] CSV parser handles lines within documented field limits
- [ ] You can explain what the null terminator is and why it matters

## Next Module

[Module 1.5 — Basic Debugging and Git Fundamentals](../module-01-05-debugging-git/README.md)
