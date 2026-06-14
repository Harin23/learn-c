# Project 35: Virtual Memory Map Explorer

**Module:** 6.2 — Memory Hierarchy and Virtual Memory  
**Estimated time:** 6–7 hours

## Description

Build a tool that parses `/proc/[pid]/maps` and categorizes memory regions. Run experiments that change the map and document results.

## Usage

```bash
vmap                    # analyze self
vmap 1234               # analyze pid 1234
vmap --summary          # counts by category
```

## Categories

Classify each mapping into:

- `text` (executable code)
- `heap` (`[heap]`)
- `stack` (`[stack]`)
- `libc` / `ld` (mapped libs)
- `mmap` (anonymous or file-backed)
- `vdso` / `vvar`
- `other`

## Requirements

- Parse `/proc/<pid>/maps` lines (see `man 5 proc`)
- Handle permission string `rwxp`
- `--summary`: print count and total KB per category
- Include experiment section in `REPORT.md`:
  1. Baseline `/proc/self/maps`
  2. After `malloc(10*1024*1024)` — what changed?
  3. After `mmap` 2 MiB anonymous — what changed?

## Rubric

| Criterion | Points |
|-----------|--------|
| Parser handles real maps file | 25 |
| Category classification reasonable | 20 |
| --summary totals | 15 |
| REPORT with three experiments | 30 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

[labs/phase-06/maps_parser_starter.c](../../labs/phase-06/maps_parser_starter.c)

## Extension (Optional)

Read `VmRSS` from `/proc/pid/status` alongside maps.
