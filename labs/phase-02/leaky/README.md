# Leaky Program Lab

Intentional memory bugs for Valgrind practice (Module 2.5 / Project 12).

## Run

```bash
make
valgrind --leak-check=full --show-leak-kinds=all ./leaky
```

Test input:

```
Alice
Bob
Carol
```

## Task

Fix all bugs until Valgrind reports zero errors and zero leaks. Write `REPORT.md` per project spec.

## Answers

See [BUGS.md](BUGS.md) only after attempting the lab.
