# Part 2 Resources

Canonical reading list for Part 2 — Memory and Core C.

## Primary Text

**The C Programming Language** (Kernighan & Ritchie)

| Module | Chapters / Sections |
|--------|---------------------|
| 2.1 | Chapter 5 — Pointers and Arrays |
| 2.2 | Chapter 5 — malloc/free (edition-dependent); `man 3 malloc` |
| 2.3 | Chapter 5; stack discussion in CS:APP (optional) |
| 2.4 | Function pointers section (edition-dependent) |
| 2.5 | Review Ch. 5; defensive coding habits |

## Man Pages (Essential)

```bash
man 3 malloc
man 3 free
man 3 realloc
man 3 calloc
man 3 qsort
man 1 valgrind
man 3 errno
```

## Valgrind

- [Valgrind Quick Start Guide](https://valgrind.org/docs/manual/quick-start.html)
- [Memcheck User Manual](https://valgrind.org/docs/manual/mc-manual.html)

Install on Ubuntu:

```bash
sudo apt install valgrind
```

Common invocation:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./program
```

## Optional but Excellent

| Resource | Notes |
|----------|-------|
| *Computer Systems: A Programmer's Perspective* (CS:APP), Ch. 3 | Stack frames, memory hierarchy |
| *Effective C* (Robert Seacord) | C pitfalls and security |
| GDB watchpoints | `watch variable` in GDB manual |

## AddressSanitizer (Preview)

Modern alternative to Valgrind for leak/overflow detection:

```bash
gcc -Wall -Wextra -std=c11 -g -fsanitize=address -o prog prog.c
./prog
```

Use alongside Valgrind in Module 2.5 optional exercises.

## Reading Order Summary

1. K&R Chapter 5 + Module 2.1 labs and Project 8
2. `man malloc` + grow array lab + Project 9
3. CS:APP stack section (optional) + Module 2.3 + Project 10
4. `man qsort` + Module 2.4 + Project 11
5. Valgrind manual + leaky lab + Project 12

## Gate to Part 3 / Part 4

Both Part 3 (data structures) and Part 4 (Linux user-space) require Part 2 exit criteria. Part 4 specifically requires pointer and malloc fluency — do not skip this part.
