# Module 4.1 — Linux Filesystem and File I/O

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Navigate the Linux filesystem hierarchy and permissions model
- Perform file I/O with POSIX syscalls (`open`, `read`, `write`, `close`, `lseek`)
- Use `stat` to inspect file metadata
- Traverse directories with `opendir`, `readdir`, `closedir`
- Handle `errno` after failed syscalls
- Build CLI utilities similar to `cat`, log tools, and file organizers

## Prerequisites

- [Part 2 exit gate](../../part-02-memory-core-c/README.md#part-exit-gate)
- Part 3 recommended

## Concepts to Study

1. **Filesystem hierarchy** — `/`, `/home`, `/proc`, `/dev`, `/etc`
2. **File descriptors** — integers; 0 stdin, 1 stdout, 2 stderr
3. **POSIX I/O** — `open(2)`, `read(2)`, `write(2)`, `close(2)`
4. **Flags** — `O_RDONLY`, `O_WRONLY`, `O_RDWR`, `O_CREAT`, `O_TRUNC`, `O_APPEND`
5. **Permissions** — `0644`, `0755`; umask
6. **`errno`** — check after `-1` return; `perror`, `strerror`
7. **`stat`** — file size, mode, mtime
8. **Directory entries** — `dirent`; skip `.` and `..`
9. **Buffered vs unbuffered** — stdio vs raw syscalls; when each fits

## Hands-On Labs

### Lab 1: File Copy with POSIX I/O

Copy a file using `open`/`read`/`write` in a loop with a buffer (4096 bytes).

Starter: [labs/part-04/copy_starter.c](../../labs/part-04/copy_starter.c)

### Lab 2: Directory Listing

List files in a directory with type and size from `stat`.

Starter: [labs/part-04/listdir_starter.c](../../labs/part-04/listdir_starter.c)

### Lab 3: Read `/proc/self/status`

Open and print first 10 lines of `/proc/self/status`. Preview for Module 4.2.

### Lab 4: Syscall vs stdio

Implement same copy once with POSIX I/O and once with `fopen`/`fread`/`fwrite`. Compare code and behavior.

## Mini-Projects

Complete all three:

1. **mycat** — [projects/part-04/19-mycat.md](../../projects/part-04/19-mycat.md)
2. **Log parser** — [projects/part-04/20-log-parser.md](../../projects/part-04/20-log-parser.md)
3. **File organizer** — [projects/part-04/21-file-organizer.md](../../projects/part-04/21-file-organizer.md)

Sample log: [labs/part-04/testdata/sample.log](../../labs/part-04/testdata/sample.log)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 2 open`, `man 2 read`, `man 2 write`, `man 3 opendir` | Primary |
| *Advanced Programming in the UNIX Environment* (Stevens) Ch. 3–4 | APUE |
| `man 7 path` | Filesystem path resolution |

## Exit Criteria

Before advancing to Module 4.2, confirm:

- [ ] All three mini-projects pass rubrics
- [ ] Syscalls check return values and use `errno`/`perror`
- [ ] File organizer creates directories as needed
- [ ] You can explain difference between file descriptor and `FILE*`

## Next Module

[Module 4.2 — Processes and Signals](../module-04-02-processes-signals/README.md)
