# Part 1 Resources

Canonical reading list and reference material for Part 1. Work through resources in parallel with modules, not all upfront.

## Primary Text

**The C Programming Language** (Brian W. Kernighan & Dennis M. Ritchie)

| Module | Chapters |
|--------|----------|
| 1.1 | Chapter 1 |
| 1.2 | Chapters 1–3 |
| 1.3 | Chapters 1, 4 |
| 1.4 | Chapters 5 (partial), 6 |
| 1.5 | Review all; focus on debugging habits |

## Man Pages

Read these as you encounter the corresponding topics:

```bash
man 3 printf
man 3 scanf
man 3 fopen
man 3 fgets
man 3 string
man gcc
man gdb
```

## Git

**Pro Git** (Scott Chacon & Ben Straub) — free online: https://git-scm.com/book/en/v2

| Module | Chapters |
|--------|----------|
| 1.5 | Chapters 1–3 (Basics, Git Basics, Git Branching) |

## Debugging

- **Debugging with GDB** — free GNU manual: https://sourceware.org/gdb/current/onlinedocs/gdb/
- Module 1.5 labs use GDB extensively; bookmark the command reference

## Supplementary (Optional)

- [CS50 C Reference](https://cs50.harvard.edu/x/) — quick syntax lookup
- [C FAQ](http://c-faq.com/) — common questions (verify against C11)

## Tools to Install

See [docs/environment-setup.md](../docs/environment-setup.md).

Valgrind is mentioned in Module 1.5 and required in Part 2.5:

```bash
sudo apt install valgrind
```

## Reading Order Summary

1. K&R Chapter 1 + Module 1.1 labs
2. K&R Chapters 2–3 + Module 1.2 projects
3. K&R Chapter 4 + Module 1.3 Makefile lab
4. K&R Chapters 5–6 + Module 1.4 projects
5. GDB manual + Pro Git + Module 1.5 capstone
