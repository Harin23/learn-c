# Module 8.3 — Kernel Subsystems and APIs

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Follow Linux kernel coding style for small patches
- Use `printk` and kernel log levels appropriately
- Recognize common kernel types and error idioms (`IS_ERR`, `PTR_ERR`)
- Read (not reimplement) `list_head` and `container_of` usage
- Produce a `Signed-off-by` patch that builds and runs in your VM

## Prerequisites

- Completed [Module 8.2](../module-08-02-kernel-build-system/README.md) exit criteria
- Working VM boot of your custom kernel from Project 43

## Concepts to Study

1. **Coding style** — tabs, 80 columns, brace placement; `Documentation/process/coding-style.rst`
2. **`printk` / `pr_*` helpers** — `KERN_DEBUG`, `KERN_INFO`; rate limiting preview
3. **Kernel integers** — `u32`, `size_t`, `pid_t`; no `<stdio.h>` in kernel code
4. **Error handling** — `IS_ERR`, `PTR_ERR`, `ERR_PTR`; `-ENOMEM` pattern
5. **`list_head`** — doubly linked lists in kernel; recognize in VFS/mm code
6. **`container_of`** — recover struct from embedded member (read-only)
7. **Kconfig-guarded debug** — `#ifdef CONFIG_*` for optional instrumentation
8. **`checkpatch.pl`** — automated style review before self-review checklist

## Hands-On Labs

### Lab 1: Coding Style Worksheet

Fix deliberately bad patch hunks in [labs/part-08/worksheets/8.3-coding-style-lab.md](../../labs/part-08/worksheets/8.3-coding-style-lab.md) (paper exercise; no compile required).

### Lab 2: Add Guarded Debug Printk

Add a one-line `pr_debug` or `printk(KERN_DEBUG ...)` on the syscall path you traced in Part 7 (e.g. near `vfs_read`). Guard with `#ifdef CONFIG_DEBUG_FS` or a local `CONFIG_LEARN_C_DEBUG` if you add a Kconfig snippet (optional advanced).

Rebuild, boot VM, trigger syscall, confirm message in `dmesg` once.

### Lab 3: checkpatch Review

```bash
cd "$KERNEL_SRC"
git diff | scripts/checkpatch.pl --strict --no-signoff -
```

Fix reported issues or document justified exceptions in patch notes.

### Lab 4: Signed-off-by Patch

Apply [kernel-patch-review-checklist.md](../../labs/part-08/checklists/kernel-patch-review-checklist.md) before exporting:

```bash
git format-patch -1 HEAD --stdout > ~/learn-c-debug.patch
```

## Mini-Project

**Syscall Debug Patch** — [projects/part-08/44-syscall-debug-patch.md](../../projects/part-08/44-syscall-debug-patch.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/process/coding-style.rst` | Required reading |
| `Documentation/process/submitting-patches.rst` | DCO, patch format |
| `scripts/checkpatch.pl` | Style checker |
| Part 7 [patch checklist](../../labs/part-07/checklists/patch-review-checklist.md) | User-space baseline |

## Exit Criteria

Before advancing to Module 8.4, confirm:

- [ ] Worksheet 8.3 completed
- [ ] Debug message visible in VM `dmesg` when syscall exercised
- [ ] checkpatch run; issues fixed or documented
- [ ] Patch includes `Signed-off-by` line
- [ ] Project 44 deliverables complete

## Next Module

[Module 8.4 — Kernel Memory Management and Scheduling](../module-08-04-kernel-mm-and-scheduling/README.md)
