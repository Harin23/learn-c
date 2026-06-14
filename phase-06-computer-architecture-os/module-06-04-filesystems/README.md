# Module 6.4 — Filesystems and I/O Subsystems

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain how a path resolves through VFS to a concrete filesystem (ext4)
- Describe inodes, dentries, and superblock roles
- Trace block device I/O path for a buffered read
- Use `stat`, `debugfs`, and `/sys/fs/ext4` for observation (read-only)
- Connect Phase 4 file I/O to kernel page cache behavior

## Prerequisites

- Completed [Module 6.3](../module-06-03-scheduling/README.md) exit criteria
- Phase 4 file I/O projects

## Concepts to Study

1. **VFS** — uniform `open/read/write` across filesystem types
2. **Inode** — metadata + block pointers; not filename
3. **Dentry cache** — directory entry cache; path lookup
4. **Block layer** — filesystem → bio → driver
5. **Page cache** — file contents cached in RAM; `drop_caches` mention (root only)
6. **ext4 layout preview** — extents, journal for crash consistency
7. **Hard vs soft links** — inode link count
8. **`stat` fields** — `st_ino`, `st_blocks`, `st_blksize`

## Hands-On Labs

### Lab 1: stat Comparison

Compare `stat` on small file vs large file; note `Blocks` and `IO Block`.

Starter: [labs/phase-06/stat_compare_starter.sh](../../labs/phase-06/stat_compare_starter.sh)

### Lab 2: Same Inode, Hard Link

Create hard link; verify same `st_ino` with `stat -c '%i'`.

### Lab 3: strace Read Path

`strace -e openat,read,close cat file` — count read sizes; relate to block size.

### Lab 4: debugfs (read-only)

On a test image or with sudo on loop device (optional advanced):

```bash
sudo debugfs -R 'stat <filename>' /dev/sda1   # only if instructed safely
```

Safer: use `dumpe2fs` read-only on lecture slides; lab uses `stat` only.

## Mini-Project

**Inode and Filesystem Lab** — [projects/phase-06/37-inode-filesystem-lab.md](../../projects/phase-06/37-inode-filesystem-lab.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| TLPI Ch. 14 | Files |
| Linux VFS documentation in kernel tree | Phase 7 |
| `man 2 stat`, `man 1 stat` | Metadata |

## Exit Criteria

Before advancing to Module 6.5, confirm:

- [ ] Can explain difference between pathname, dentry, and inode
- [ ] Hard link lab shows identical inode numbers
- [ ] Project 37 report traces read from user `read()` to cache/block layer (diagram)
- [ ] strace read pattern documented

## Next Module

[Module 6.5 — Device Drivers, Interrupts, and Caches](../module-06-05-drivers-interrupts-caches/README.md)
