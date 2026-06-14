# Part 4 Resources

Canonical reading list for Part 4 — Linux User-Space Development.

## Primary Text

**Advanced Programming in the UNIX Environment** (W. Richard Stevens, Stephen Rago) — APUE

| Module | APUE Chapters |
|--------|---------------|
| 4.1 | 3–4 (file I/O, directories) |
| 4.2 | 3, 8, 10 (proc info, processes, signals) |
| 4.3 | 11 (threads) |
| 4.4 | 15–16 (IPC) |
| 4.5 | Build via practical Makefile work |
| 4.6 | 7 (process environment), linking chapters |

Free alternative: **The Linux Programming Interface** (Michael Kerrisk) — similar coverage.

## Essential Man Pages

### File I/O (Module 4.1)

```bash
man 2 open read write close lseek stat
man 3 opendir readdir closedir
man 2 rename mkdir
man 3 errno perror
```

### Processes and Signals (Module 4.2)

```bash
man 5 proc
man 2 getpid getppid
man 2 sigaction kill
man 7 signal
```

### Threads (Module 4.3)

```bash
man 3 pthread_create pthread_join pthread_mutex_lock
man 3 termios
```

### IPC (Module 4.4)

```bash
man 2 pipe mmap
man 3 shm_open sem_open
man 7 sem_overview
```

### Libraries (Module 4.6)

```bash
man 1 ar ld ldd
man 8 ldconfig
```

## Package Notes (Ubuntu)

```bash
sudo apt install -y manpages-posix manpages-posix-dev
```

Link pthread programs:

```bash
gcc ... -pthread
# or
gcc ... -lpthread
```

Shared memory / realtime:

```bash
gcc ... -lrt -pthread
```

## Linux Filesystem Hierarchy

| Path | Purpose |
|------|---------|
| `/proc` | Process and kernel info |
| `/dev` | Device files |
| `/etc` | Configuration |
| `/home` | User data |
| `/tmp` | Temporary files |

## Reading Order Summary

1. APUE Ch. 3–4 + Module 4.1 + Projects 19–21
2. `man 5 proc` + APUE signals + Module 4.2 + Projects 22–23
3. APUE threads + Module 4.3 + Project 24
4. APUE IPC + Module 4.4 + Project 25
5. GNU Make manual + Module 4.5 makefile lab
6. Linking docs + Module 4.6 + Project 26

## Gate to Part 5

Part 5 introduces `fork`, `exec`, pipes between processes, and networking. Part 4 exit gate ensures you can read `/proc`, handle signals, use threads, and build with Make/libraries before those syscalls.
