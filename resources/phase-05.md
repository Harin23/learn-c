# Phase 5 Resources

Canonical reading list for Phase 5 — Linux Systems Programming.

## Primary Texts

| Resource | Modules |
|----------|---------|
| **Advanced Programming in the UNIX Environment** (Stevens/Rago) | All — especially Ch. 8, 10–11, 15–17 |
| **The Linux Programming Interface** (Michael Kerrisk) | Syscalls, processes, IPC, signals, sockets |
| [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) | 5.5 networking |

## Essential Man Pages

### System Calls and Processes (5.1–5.2)

```bash
man 2 syscalls intro fork execve waitpid _exit
man 1 strace
```

### Pipes (5.3)

```bash
man 2 pipe dup dup2
man 3 popen
```

### Threads (5.4)

```bash
man 3 pthread_create pthread_join pthread_mutex_lock
man 3 pthread_cond_wait pthread_cond_signal
```

### Networking (5.5)

```bash
man 7 ip tcp socket bind listen accept connect
man 3 inet_pton htons getaddrinfo
```

### Event-Driven (5.6)

```bash
man 2 select poll
man 7 epoll
man 7 inotify
```

## Tools

```bash
sudo apt install strace net-tools
strace -f -e trace=process ./myshell
ss -tlnp          # list listening TCP ports
curl -v http://127.0.0.1:8080/
nc 127.0.0.1 9000 # test chat/echo
```

## strace Tips

```bash
strace -c ./program           # syscall summary
strace -e trace=network ./http_server
strace -f -o log.txt ./shell  # follow forks
```

## Reading Order Summary

1. TLPI Ch. 2 + strace labs + Module 5.1
2. APUE Ch. 8 + fork/exec labs + Project 27
3. APUE Ch. 15 + pipe labs + Project 28
4. APUE Ch. 11 + condvar/tpool + Project 29
5. Beej's Guide + echo/HTTP labs + Projects 30–31
6. man inotify/select + Module 5.6 + Projects 32–33

## Gate to Phase 6

Phase 6 explains *why* syscalls behave as they do (CPU, VM, scheduling). Phase 5 gives you practical mastery; Phase 6 connects it to hardware and kernel internals before Phase 8 kernel development.
