# Project 26: Static + Shared Library Demo (Part 4 Capstone)

**Module:** 4.6 — Static and Shared Libraries  
**Estimated time:** 6–8 hours

## Description

Extract a utility library from your Part 4 work; build as `.a` and `.so`; link two demo programs against each.

## Layout

```
libdemo/
├── Makefile
├── include/
│   └── util.h
├── src/
│   └── util.c
├── apps/
│   ├── cat_main.c      # uses util_read_file
│   └── hash_main.c     # uses util_hash_string
├── lib/
│   ├── libutil.a       # built
│   └── libutil.so      # built
└── README.md
```

## Public API (util.h)

```c
/* Read entire file into malloc'd buffer; caller frees. Returns bytes read or -1. */
long util_read_file(const char *path, char **out, size_t *out_len);

/* djb2 hash of string */
unsigned long util_hash_string(const char *s);

/* Trim trailing newline in place */
void util_chomp(char *s);
```

## Makefile Targets

| Target | Builds |
|--------|--------|
| `all` | static-linked apps in `build/` |
| `shared` | `.so` and apps linked against shared lib |
| `clean` | remove artifacts |
| `test` | run smoke tests |

## Requirements

- `util.c` functions are shared by both apps
- Static build: link `libutil.a` directly
- Shared build: `-fPIC` for objects in library; `-Llib -lutil`; document `LD_LIBRARY_PATH=lib` or rpath
- Hide internal helpers as `static` in `util.c`
- README explains static vs shared trade-offs on your system

## Rubric

| Criterion | Points |
|-----------|--------|
| Both apps work with static lib | 25 |
| Both apps work with shared lib | 25 |
| Clean public header (no leaked internals) | 15 |
| Makefile targets all/shared/clean | 15 |
| README comparison of .a vs .so | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Verification

```bash
make clean && make all
make shared
LD_LIBRARY_PATH=lib ./build/hash_main /etc/hostname
ldd ./build/hash_main_shared
nm lib/libutil.a | head
```

## Starter

[labs/part-04/lib_demo/](../../labs/part-04/lib_demo/)

## Part 4 Completion

Passing this project (≥80 points) plus Projects 19–25 completes Part 4.
