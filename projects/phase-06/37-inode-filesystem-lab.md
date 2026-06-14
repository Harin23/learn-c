# Project 37: Inode and Filesystem Lab

**Module:** 6.4 — Filesystems and I/O Subsystems  
**Estimated time:** 6–7 hours

## Description

Investigate file metadata and path resolution on ext4 (or default root fs). Produce a report with diagrams — minimal new code, heavy observation.

## Part A — Metadata Tool (`fstat` CLI)

```bash
fstat file.txt
fstat -l linkname
```

Print:

- inode number (`st_ino`)
- link count (`st_nlink`)
- size, preferred block size (`st_blksize`)
- blocks allocated (`st_blocks` × 512)
- device major/minor (`st_dev`)

## Part B — Experiments (document in `REPORT.md`)

1. **Hard link:** create `a` and `b` hard linked; show same inode; delete one; show `nlink`
2. **Small vs large file:** compare `st_blocks` for 1-byte file vs 1 MiB file
3. **strace read:** `strace -e openat,read,close dd if=file bs=4096 count=1 2>&1 | head` — relate read size to block size
4. **Path lookup diagram:** draw VFS path walk for `/home/user/docs/file.txt` (boxes: pathname → dentry → inode → page cache → bio)

## Part C — Optional Code

Implement `fstat` in C using `stat(2)` and `lstat(2)` for symlinks.

## Rubric

| Criterion | Points |
|-----------|--------|
| fstat output correct | 25 |
| Hard link experiment | 20 |
| strace read analysis | 15 |
| VFS diagram quality | 25 |
| REPORT clear and accurate | 15 |
| **Total** | **100** |

## Starter

[labs/phase-06/fstat_starter.c](../../labs/phase-06/fstat_starter.c)

## Safety

Do not run destructive `debugfs` commands on your root filesystem. Observation-only on live files.
