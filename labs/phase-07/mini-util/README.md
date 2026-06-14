# mini-util

Small user-space utilities for Phase 7 codebase reading and patch practice.

Not a real production project — intentional beginner-friendly bugs for [Project 41](../../../projects/phase-07/41-small-patch-submission.md).

## Build

```bash
make
make test
```

## Binaries

| Command | Source |
|---------|--------|
| `mu-wc` | `src/mu_wc.c` |
| `mu-cat` | `src/mu_cat.c` |

## Navigation exercises

```bash
ctags -R .
rg 'count_words' src/
git log --oneline
```

## Issues

See [ISSUES.md](ISSUES.md) for patch targets.
