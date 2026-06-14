# Project 40: Kernel Subsystem Trace

**Module:** 7.2 — Linux Source Tree Structure  
**Estimated time:** 10–12 hours

## Description

Trace one system call from the x86-64 syscall entry through the Virtual File System layer (or memory management for `mmap`/`brk`). Document file paths and function names — **read-only**, no kernel build required.

## Choose one trace path

| Syscall | Suggested chain end |
|---------|---------------------|
| `read` | `vfs_read` → file `read_iter` |
| `openat` | `do_sys_openat2` → path lookup |
| `mmap` | `ksys_mmap_pgoff` → `vm_mmap` (mm/) |
| `write` | `vfs_write` |

## Deliverable: `KERNEL_TRACE.md`

### 1. Environment

- Kernel version (e.g. `v6.x` tag or Elixir version)
- Tools: local clone vs Bootlin Elixir

### 2. Trace table

| Step | Function | File path |
|------|----------|-----------|
| 1 | user `read()` libc | ... |
| 2 | syscall entry | `arch/x86/entry/...` |
| ... | ... | ... |
| N | filesystem read | `fs/...` |

Minimum **8 steps** with real paths verified in source.

### 3. Subsystem map

ASCII or mermaid diagram placing traced code in context of `kernel/`, `mm/`, `fs/`, `drivers/`.

### 4. MAINTAINERS

Copy relevant MAINTAINERS subsection for traced files.

### 5. Documentation link

One `Documentation/` file that explains this area; 5-line summary.

## Rubric

| Criterion | Points |
|-----------|--------|
| Trace table accurate (spot-check 3 entries) | 35 |
| Subsystem diagram | 20 |
| MAINTAINERS included | 10 |
| Documentation summary | 15 |
| Worksheet 7.2 completed | 10 |
| Clear citations (file:line) | 10 |
| **Total** | **100** |

## Worksheet

[labs/phase-07/worksheets/7.2-kernel-tree-tour.md](../../labs/phase-07/worksheets/7.2-kernel-tree-tour.md)

## Note

Exact function names vary by kernel version — document your version and stay consistent.
