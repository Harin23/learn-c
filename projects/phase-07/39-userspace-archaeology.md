# Project 39: User-Space Codebase Archaeology

**Module:** 7.1 — Navigating Open-Source Repositories  
**Estimated time:** 8–10 hours

## Description

Choose a real user-space C project and produce a structured exploration report tracing one command or feature from entry point to core logic.

## Project Choices (pick one)

| Project | Trace target |
|---------|--------------|
| GNU coreutils | `wc`, `cat`, or `ls` |
| util-linux | `dmesg`, `kill`, or `hexdump` |
| busybox | one applet (e.g. `true`, `echo`) |
| toybox | one command |

**Alternative:** [mini-util](../../labs/phase-07/mini-util/) `mu-wc` if bandwidth/time limited — note in report.

## Deliverable: `ARCHAEOLOGY.md`

Required sections:

### 1. Repository orientation

- Clone URL and version/tag
- Build commands used (copy from docs)
- Top-level directory map (5–10 bullets)

### 2. Search trail

Document exact commands:

```bash
rg 'pattern' ...
git log --oneline -5 -- path/to/file.c
git blame -L 10,30 path/to/file.c
```

At least **8 commands** with one-line interpretation each.

### 3. Call graph

Diagram or indented list from `main` (or applet entry) to ≥5 functions deep for chosen command.

### 4. Key data structures

Describe 1–2 structs or global configs that affect behavior.

### 5. Surprise or question

One thing that was non-obvious; one question you'd ask maintainers.

## Rubric

| Criterion | Points |
|-----------|--------|
| Successful build from upstream docs | 15 |
| Call graph depth and accuracy | 30 |
| Search trail with real commands | 25 |
| Data structure discussion | 15 |
| Clear writing | 15 |
| **Total** | **100** |

## Worksheet

Start with [7.1-mini-util-orientation.md](../../labs/phase-07/worksheets/7.1-mini-util-orientation.md) for practice.
