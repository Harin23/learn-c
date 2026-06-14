# Module 4.6 — Static and Shared Libraries

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Build static libraries (`.a`) with `ar`
- Build shared libraries (`.so`) with `-fPIC` and `-shared`
- Link against libraries at compile time and run time
- Understand `LD_LIBRARY_PATH` and `ldconfig` basics
- Export a clean public API from `libfoo.h` while hiding internals
- Complete Part 4 with production-style project layout

## Prerequisites

- Completed [Module 4.5](../module-04-05-build-systems/README.md) exit criteria

## Concepts to Study

1. **Static linking** — `.a` archive embedded in executable; larger binary, no runtime dep
2. **Shared linking** — `.so` loaded at runtime; smaller exe, one copy in memory
3. **`-fPIC`** — position-independent code required for shared libs
4. **`ar rcs libfoo.a foo.o`** — create static archive
5. **`-Lpath -lfoo`** — link search path and library name (`libfoo.so` → `-lfoo`)
6. **`rpath`** — `-Wl,-rpath,$ORIGIN/../lib` for relocatable installs
7. **Symbol visibility** — static functions in `.c` files hide implementation
8. **ABI preview** — changing struct layout breaks consumers

## Hands-On Labs

### Lab 1: Static Library Math Utils

Extract string/parse utilities from earlier projects into `libutil.a`.

Starter: [labs/part-04/lib_demo/](../../labs/part-04/lib_demo/)

### Lab 2: Convert to Shared Library

Same API as `.so`; run with and without `LD_LIBRARY_PATH`.

### Lab 3: Multiple Consumers

Two binaries link same shared library; modify library, recompile library only, rerun without relinking apps (when ABI unchanged).

### Lab 4: Inspect Symbols

```bash
nm libutil.a
nm -D libutil.so
ldd ./myapp
```

## Mini-Project

**Static + Shared Library Demo** — [projects/part-04/26-library-demo.md](../../projects/part-04/26-library-demo.md)

## Part 4 Oral Checklist (Self-Assessment)

Answer without notes:

1. What does `open(2)` return on error?
2. Where is process command line stored in `/proc`?
3. Why use `pthread_mutex`?
4. Pipe vs shared memory — one trade-off?
5. What does `-fPIC` do?
6. Difference between `.a` and `.so`?

## Exit Criteria

Before advancing to Part 5, confirm:

- [ ] Library demo project passes rubric (static and shared builds)
- [ ] Public header exposes only intended API
- [ ] `ldd` shows correct shared library resolution
- [ ] All Projects 19–26 complete with zero warnings
- [ ] Part 4 oral checklist completed confidently
- [ ] [Part 4 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 5 — Linux Systems Programming](../../part-05-linux-systems-programming/) (coming soon)
