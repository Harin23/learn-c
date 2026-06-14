# Phase 6 Resources

Canonical reading list for Phase 6 — Computer Architecture and Operating Systems.

## Primary Text

**Computer Systems: A Programmer's Perspective** (CS:APP) — 3rd edition

| Module | CS:APP Chapters |
|--------|-----------------|
| 6.1 | Ch. 3 — Machine-level program representation |
| 6.2 | Ch. 9 — Virtual memory |
| 6.3 | Ch. 8 (processes), OS scheduling supplements |
| 6.4 | Ch. 10 — System-level I/O (files) |
| 6.5 | Ch. 6 — Memory hierarchy; Ch. 5 (optimization) |

**The Linux Programming Interface** (Kerrisk) — Ch. 12 (shared memory recap), 14 (files), 20 (virtual memory)

**Operating Systems: Three Easy Pieces** (OSTEP) — free online: [ostep.org](https://ostep.org/)

| Module | OSTEP Topics |
|--------|--------------|
| 6.2 | Virtual memory chapters |
| 6.3 | Scheduling |
| 6.4 | Filesystems |
| 6.5 | I/O devices, disks |

## Tools

```bash
sudo apt install binutils   # objdump, readelf
gcc -S -O0 -g file.c
objdump -d -M intel prog
readelf -h prog
cat /proc/self/maps
cat /proc/interrupts
perf stat ./program         # optional, linux-tools-generic
```

## Kernel Documentation (Preview for Phase 7–8)

- `Documentation/admin-guide/mm/` — memory management
- `Documentation/filesystems/vfs.rst` — VFS overview
- `Documentation/core-api/` — kernel internals index

## Man Pages

```bash
man 5 proc
man 2 mmap mprotect mincore
man 2 stat
man 7 sched
```

## Reading Order Summary

1. CS:APP Ch. 3 + GDB/objdump labs + Project 34
2. CS:APP Ch. 9 + maps/mmap labs + Project 35
3. OSTEP scheduling + simulator + Project 36
4. OSTEP filesystems + stat/strace + Project 37
5. CS:APP Ch. 6 + cache lab + Project 38

## Gate to Phase 8

Phase 8 (kernel development) assumes you understand virtual memory, scheduling, and filesystem path lookup. Complete Phase 7 (reading code) in parallel or before Phase 8.
