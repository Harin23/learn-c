# Module 5.1 — System Calls

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain the system call interface between user space and the kernel
- Distinguish library functions (libc) from raw syscalls
- Trace program execution with `strace`
- Read syscall numbers and signatures in `man 2`
- Understand errno propagation across the user/kernel boundary
- Recognize syscalls used in your Phase 4 projects retroactively

## Prerequisites

- Completed [Phase 4 exit gate](../../phase-04-linux-user-space/README.md#phase-exit-gate)

## Concepts to Study

1. **User mode vs kernel mode** — privileged instructions; syscall as controlled entry
2. **Syscall mechanism** — `syscall` instruction on x86-64; register conventions preview
3. **libc wrappers** — `write(3)` vs `write(2)`; most code uses wrappers
4. **`strace`** — trace syscalls: `strace -f ./program`
5. **Return values** — `-1` on error, `errno` set; same pattern as Phase 4
6. **Common syscalls** — read, write, open, close, stat, mmap, brk, futex preview
7. **`/usr/include/asm/unistd_64.h`** — syscall numbers (read-only exploration)
8. **VDSO** — fast gettimeofday without full syscall (mention)

## Hands-On Labs

### Lab 1: strace Hello World

```bash
strace -o trace.log ./hello
grep -E 'write|exit' trace.log
```

Write three sentences explaining each `write` call you see.

### Lab 2: Compare libc and Syscall Path

Trace `cat file` vs your mycat. Count read/write syscalls for same file size.

### Lab 3: errno Exploration

Call `open("/nonexistent", O_RDONLY)` and print `errno` with `strerror`.

Starter: [labs/phase-05/errno_starter.c](../../labs/phase-05/errno_starter.c)

### Lab 4: Syscall Inventory

Pick Project 20 (log parser). List every distinct syscall it makes under `strace -c`.

## Module Integration

No standalone project number — mastery shown through strace reports in Projects 27–33 README requirements.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 2 syscalls`, `man 2 intro` | Overview |
| `man 1 strace` | Tracing |
| APUE Ch. 1 | UNIX architecture |
| *The Linux Programming Interface* Ch. 2 | LTP overview |

## Exit Criteria

Before advancing to Module 5.2, confirm:

- [ ] Can run `strace` and identify read/write/open/close in output
- [ ] Can explain why syscalls are needed
- [ ] errno lab prints correct message for ENOENT
- [ ] Syscall inventory document written for one Phase 4 program
- [ ] You know the difference between `man 2` and `man 3`

## Next Module

[Module 5.2 — fork() and exec()](../module-05-02-fork-exec/README.md)
