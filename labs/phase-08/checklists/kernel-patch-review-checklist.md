# Kernel Patch Review Checklist — Phase 8

Use before exporting kernel patches (Projects 44 and 46). Extends [Phase 7 patch checklist](../../phase-07/checklists/patch-review-checklist.md).

## Scope and correctness

- [ ] One logical change per commit (or justified series)
- [ ] Patch applies cleanly on documented kernel tag
- [ ] Kernel builds after patch (`make bzImage` or agreed target)
- [ ] VM boot tested when code paths changed (required for code patches)

## Kernel style

- [ ] Follows `Documentation/process/coding-style.rst` (tabs, braces, 80 columns)
- [ ] `checkpatch.pl --strict` run; issues fixed or explained in notes
- [ ] No user-space headers (`stdio.h`, etc.) in kernel code
- [ ] Appropriate log level (`pr_debug` vs `printk` noise)

## Locking and context

- [ ] No sleeping in atomic/interrupt context
- [ ] No long work under spinlocks
- [ ] Debug code does not introduce new lock inversions (lockdep clean boot if possible)

## Patch metadata

- [ ] Commit subject ≤72 characters, imperative mood
- [ ] Body explains **why**, not only what
- [ ] `Signed-off-by: Your Name <email@example.com>` present (DCO)
- [ ] Diff excludes unrelated whitespace or drive-by changes

## Testing evidence

- [ ] Steps to reproduce / verify documented
- [ ] `dmesg` or ftrace evidence attached for behavior changes
- [ ] Kernel version and config notes included

## Reviewer mindset

- [ ] Would a maintainer understand this without a verbal explanation?
- [ ] Is this minimal for the stated goal?
- [ ] MAINTAINERS subsystem identified (for real upstream later)

## Sign-off

Patch title: _______________  
checkpatch warnings remaining: _______________  
VM boot after patch: yes / no / N/A  
