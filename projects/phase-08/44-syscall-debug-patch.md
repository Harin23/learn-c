# Project 44: Syscall Debug Patch

**Module:** 8.3 — Kernel Subsystems and APIs  
**Estimated time:** 12–14 hours

## Description

Add minimal, guarded debug instrumentation on the syscall path you traced in Phase 7 Project 40. Rebuild the kernel, boot in VM, trigger the syscall, and confirm output in `dmesg`.

## Choose one path (same as Project 40 if possible)

| Syscall | Suggested insertion point |
|---------|---------------------------|
| `read` | near `vfs_read` in `fs/read_write.c` |
| `openat` | near `do_filp_open` / path lookup |
| `write` | near `vfs_write` |
| `mmap` | near `ksys_mmap_pgoff` / `vm_mmap` |

## Requirements

1. **One logical change** — single commit preferred
2. **Guarded output** — use `pr_debug` or `printk(KERN_DEBUG ...)`; avoid flooding (rate limit or one-shot if needed)
3. **Kernel coding style** — tabs, 80 columns
4. **`Signed-off-by`** line in commit message
5. **`checkpatch.pl`** run on patch; fix or document exceptions
6. Kernel **builds and boots** in VM after patch

## Steps

1. Create branch in `$KERNEL_SRC`: `git checkout -b learn-c-syscall-debug`
2. Add debug line at chosen location
3. Rebuild `bzImage`, boot VM
4. Trigger syscall from user space (e.g. `cat /etc/hostname`, `echo test > /tmp/f`)
5. Capture `dmesg` showing your message
6. Export patch: `git format-patch -1 HEAD --stdout > syscall-debug.patch`

## Deliverables

1. **`syscall-debug.patch`** (or `0001-*.patch`)
2. **`PATCH_NOTES.md`** containing:
   - Syscall and insertion file:function
   - Why this location was chosen
   - checkpatch output summary (pass or fixed items)
   - `dmesg` snippet proving message appears
   - Kernel version tag

3. Completed [kernel-patch-review-checklist.md](../../labs/phase-08/checklists/kernel-patch-review-checklist.md) (paste checklist with checkmarks)

## Rubric

| Criterion | Points |
|-----------|--------|
| Patch applies cleanly; kernel builds | 25 |
| VM boot + syscall triggers debug message | 25 |
| Coding style / checkpatch reviewed | 20 |
| Signed-off-by + good commit message | 15 |
| PATCH_NOTES complete | 10 |
| Review checklist completed | 5 |
| **Total** | **100** |

## Worksheet

[labs/phase-08/worksheets/8.3-coding-style-lab.md](../../labs/phase-08/worksheets/8.3-coding-style-lab.md)

## Do not

- Add loadable modules (Phase 9)
- Leave unconditional `printk` on hot paths in a patch you would upstream
- Submit to mailing lists without mentor review (practice only)
