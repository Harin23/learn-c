# Module 4.5 — Build Systems and Makefiles

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Write Makefiles with variables, automatic dependencies, and pattern rules
- Split projects into multiple targets (`all`, `clean`, `install`, `debug`)
- Use `$@`, `$<`, `$^` and `$(CC)`, `$(CFLAGS)`
- Generate dependency files with `-MMD` (preview)
- Understand rebuild rules: when make rebuilds targets
- Organize source trees with `src/`, `include/`, `build/`

## Prerequisites

- Completed [Module 4.4](../module-04-04-ipc/README.md) exit criteria
- Basic Makefiles from Phase 1–3 projects

## Concepts to Study

1. **Targets and prerequisites** — `target: deps; recipe`
2. **Variables** — `CC`, `CFLAGS`, `LDFLAGS`, `LDLIBS`
3. **Pattern rules** — `%.o: %.c`
4. **Phony targets** — `.PHONY: all clean`
5. **Out-of-tree builds preview** — `build/` directory
6. **Header dependencies** — recompile when `.h` changes
7. **`-pthread` in LDLIBS** — link order matters sometimes
8. **Autotools/CMake** — mention only; hand-written Make sufficient here

## Hands-On Labs

### Lab 1: Refactor Existing Project

Take your log parser (Project 20) and restructure with:

```
project/
├── Makefile
├── include/
├── src/
└── build/    (gitignored)
```

### Lab 2: Multi-Binary Makefile

One Makefile building `mycat`, `logparser`, and `organizer` from shared `util.c`.

Starter: [labs/phase-04/makefile_lab/](../../labs/phase-04/makefile_lab/)

### Lab 3: Automatic Dependencies

Add `-MMD -MP` to compile flags; include generated `.d` files.

### Lab 4: Debug vs Release Targets

`make debug` adds `-g -O0`; default uses `-O2` (discuss optimization and debugging).

## Module Integration

No standalone project number — skills assessed via Makefile quality in Projects 19–26 and the makefile lab rubric.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html) | Ch. 2–4 |
| `man make` | Local reference |
| Linux kernel `Documentation/kbuild/` | Phase 7 preview |

## Exit Criteria

Before advancing to Module 4.6, confirm:

- [ ] Makefile lab builds three binaries from shared sources
- [ ] `make clean` removes all artifacts
- [ ] Header change triggers recompile of dependent `.c` files
- [ ] At least two Phase 4 projects use structured `src/`/`include/` layout
- [ ] You can explain what a phony target is

## Next Module

[Module 4.6 — Static and Shared Libraries](../module-04-06-libraries/README.md)
