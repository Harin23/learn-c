# Module 9.2 — Character Devices

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Allocate major/minor numbers with `alloc_chrdev_region` and register a `cdev`
- Implement `struct file_operations` (`open`, `read`, `write`, `release`)
- Copy data safely with `copy_to_user` and `copy_from_user`
- Create a device node and test from user space
- Connect char device path to Part 6 driver model preview

## Prerequisites

- Completed [Module 9.1](../module-09-01-loadable-kernel-modules/README.md) exit criteria
- Working VM with modules enabled

## Concepts to Study

1. **Char vs block devices** — byte-stream vs fixed blocks (Part 6 review)
2. **Major/minor numbers** — identity for `/dev` nodes
3. **`struct cdev`** — char device registration
4. **`file_operations`** — driver callbacks for VFS
5. **User pointers** — never dereference directly; use `copy_*_user`
6. **Return values** — bytes transferred or negative errno
7. **`MKDEV`, `register_chrdev_region`** — allocation patterns
8. **Static mknod vs `device_create`** — node creation options

## Hands-On Labs

### Lab 1: Read In-Tree Char Driver

Skim `drivers/char/mem.c` or `Documentation/core-api/` char device section — note `file_operations` layout.

### Lab 2: open() to Driver Walkthrough

Worksheet: [labs/part-09/worksheets/9.2-chardev-walkthrough.md](../../labs/part-09/worksheets/9.2-chardev-walkthrough.md)

Extend Part 7 syscall trace with driver `open` callback.

### Lab 3: chardev-buffer Starter

Build [labs/part-09/chardev-buffer/](../../labs/part-09/chardev-buffer/); create `/dev` node; test with [test_read.c](../../labs/part-09/user-tools/test_read.c) and [test_write.c](../../labs/part-09/user-tools/test_write.c).

### Lab 4: Error Paths

Test invalid user buffer (optional advanced), zero-length read/write, and partial reads from empty buffer.

## Mini-Project

**Circular Buffer Char Device** — [projects/part-09/48-chardev-buffer.md](../../projects/part-09/48-chardev-buffer.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/core-api/` | Char device registration |
| Part 6 [Module 6.5](../../part-06-computer-architecture-os/module-06-05-drivers-interrupts-caches/README.md) | Char/block preview |

## Exit Criteria

Before advancing to Module 9.3, confirm:

- [ ] Worksheet 9.2 completed
- [ ] Char device loads in VM; user test tools pass
- [ ] No oops on read/write; uses `copy_to_user`/`copy_from_user`
- [ ] Project 48 deliverables complete

## Next Module

[Module 9.3 — Sysfs and Procfs](../module-09-03-sysfs-and-procfs/README.md)
