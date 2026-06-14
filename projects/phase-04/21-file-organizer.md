# Project 21: File Organizer

**Module:** 4.1 — Linux Filesystem and File I/O  
**Estimated time:** 5–6 hours

## Description

Organize files in a directory by extension into subfolders (e.g. `pdf/`, `txt/`, `jpg/`).

## Usage

```bash
organizer /path/to/messy_dir          # dry-run: print planned moves
organizer /path/to/messy_dir --apply  # perform moves
organizer /path/to/messy_dir --apply --unknown other/
```

## Requirements

- Only regular files in top-level directory (non-recursive default)
- Extension = substring after last `.`; no dot → `--unknown` folder or `other/`
- Create destination subdirs with `mkdir` mode `0755` as needed
- Use `rename(2)` for moves
- Dry-run default: print `would move: a.txt -> txt/a.txt`

## Safety

- Do not overwrite existing destination file — skip with warning
- Refuse to operate if target is `/` or `$HOME` without `--force` (guardrail)

## Rubric

| Criterion | Points |
|-----------|--------|
| Dry-run output correct | 20 |
| --apply moves files correctly | 30 |
| Creates subdirectories | 15 |
| Handles no-extension files | 15 |
| Collision/safety checks | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Test Setup

```bash
mkdir -p test_in && touch test_in/a.txt test_in/b.pdf test_in/note
./organizer test_in
./organizer test_in --apply
ls test_in/txt test_in/pdf
```
