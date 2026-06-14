# Module 7.2 — Linux Source Tree Structure

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe top-level Linux kernel directory layout
- Locate major subsystems: `kernel/`, `mm/`, `fs/`, `drivers/`, `arch/`, `include/`
- Understand Kconfig/Kbuild role at a high level
- Trace a system call from architecture entry to subsystem handler (read-only)
- Use kernel `Documentation/` and MAINTAINERS file
- Browse kernel source online or locally without building (building is Part 8)

## Prerequisites

- Completed [Module 7.1](../module-07-01-navigating-repos/README.md) exit criteria
- Part 6 virtual memory and filesystem modules strongly recommended

## Concepts to Study

1. **Top-level tree** — what lives where; avoid reading everything
2. **`arch/x86/`** — architecture-specific entry, syscalls, boot
3. **`include/linux/`** — kernel internal headers
4. **`kernel/`** — core scheduler, signals, workqueues preview
5. **`mm/`** — memory management
6. **`fs/`** — VFS and filesystem implementations
7. **`drivers/`** — device drivers by bus/class
8. **Syscall path** — user `read()` → `SYSCALL_DEFINE` → `vfs_read` → file ops
9. **MAINTAINERS** — subsystem owners and review paths
10. **Coding style** — `Documentation/process/coding-style.rst`

## Hands-On Labs

### Lab 1: Kernel Source Checkout

```bash
git clone --depth=1 https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
# or shallow clone of stable; ~1-2 GB — allow time
```

Alternative shallow topic browse: [elixir.bootlin.com/linux/latest/source](https://elixir.bootlin.com/linux/latest/source)

Worksheet: [labs/part-07/worksheets/7.2-kernel-tree-tour.md](../../labs/part-07/worksheets/7.2-kernel-tree-tour.md)

### Lab 2: Locate Syscall Definitions

Find `__x64_sys_read` (or `ksys_read` path) and `vfs_read` in tree. Record file paths.

### Lab 3: MAINTAINERS Scavenger Hunt

Pick subsystem (e.g. EXT4, DRM, scheduler). Find maintainer entries and mailing list.

### Lab 4: Documentation Reading

Read one DocBook/RST file under `Documentation/filesystems/` or `Documentation/core-api/`; summarize in 10 lines.

## Mini-Project

**Kernel Subsystem Trace** — [projects/part-07/40-kernel-subsystem-trace.md](../../projects/part-07/40-kernel-subsystem-trace.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [Bootlin Elixir Cross Referencer](https://elixir.bootlin.com/linux/latest/source) | Online browse |
| `Documentation/admin-guide/README.rst` | Kernel docs index |
| *Linux Kernel Development* (Love) — Ch. 2–6 overview |

## Exit Criteria

Before advancing to Module 7.3, confirm:

- [ ] Worksheet 7.2 completed with correct paths for `read` syscall chain
- [ ] Can name five top-level kernel directories and their roles
- [ ] Project 40 trace document includes ≥6 functions with file paths
- [ ] You found relevant MAINTAINERS entry for traced subsystem

## Next Module

[Module 7.3 — Documentation-Driven Development and Small Fixes](../module-07-03-docs-and-small-fixes/README.md)
