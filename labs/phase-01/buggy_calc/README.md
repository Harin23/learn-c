# Lab 1.5 — Buggy Calculator

Practice finding bugs with GDB. The calculator compiles but produces wrong results and has memory safety issues.

## Build and Run

```bash
cd labs/phase-01/buggy_calc
make
./calc
```

## Tasks

1. Verify `10 / 2` returns wrong result — find with GDB in `apply_op`
2. Perform 6+ calculations — observe history corruption; fix bounds check
3. Document each bug: symptom, GDB commands used, fix applied

## Answers

See [BUGS.md](BUGS.md) only after attempting the lab yourself.
