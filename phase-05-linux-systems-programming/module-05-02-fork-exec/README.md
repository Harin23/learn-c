# Module 5.2 — fork() and exec()

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Create child processes with `fork`
- Replace process image with `execve` and variants (`execlp`, `execvp`)
- Wait for child termination with `wait`/`waitpid`
- Explain copy-on-write after `fork`
- Avoid zombie processes by reaping children
- Build a minimal interactive shell

## Prerequisites

- Completed [Module 5.1](../module-05-01-syscalls/README.md) exit criteria

## Concepts to Study

1. **`fork(2)`** — child gets duplicate address space; returns 0 in child, child PID in parent
2. **`execve(2)`** — replace memory with new program; never returns on success
3. **PATH and shebang** — kernel exec loader; `#!` line
4. **`waitpid(2)`** — block for child; status macros `WIFEXITED`, `WEXITSTATUS`
5. **Zombie vs orphan** — unreaped children; init adopts orphans
6. **File descriptor inheritance** — child inherits open fds; close before exec if needed
7. **Shell grammar preview** — parse line → argv → fork → exec → wait
8. **Safety** — never call async-unsafe functions after fork in multi-threaded process without exec

## Hands-On Labs

### Lab 1: fork Prints Twice

Parent and child print PID and message; observe different return values.

Starter: [labs/phase-05/fork_starter.c](../../labs/phase-05/fork_starter.c)

### Lab 2: exec ls

Child runs `execvp("ls", argv)`; parent waits and prints exit code.

Starter: [labs/phase-05/exec_starter.c](../../labs/phase-05/exec_starter.c)

### Lab 3: Zombie Demo and Fix

Create unreaped child; observe with `ps`; fix with `waitpid`.

### Lab 4: Simple Command Runner

Parse `cmd arg1 arg2`, fork, exec, wait — precursor to shell.

## Mini-Project

**Custom Shell** — [projects/phase-05/27-custom-shell.md](../../projects/phase-05/27-custom-shell.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 2 fork`, `man 2 execve`, `man 2 waitpid` | Primary |
| APUE Ch. 8 | Process control |

## Exit Criteria

Before advancing to Module 5.3, confirm:

- [ ] fork/exec lab runs external program correctly
- [ ] No zombie children left after shell commands
- [ ] Custom shell runs builtins (`cd`, `exit`) and external commands
- [ ] strace shows fork/execve/waitpid sequence for one command
- [ ] You can explain copy-on-write at a high level

## Next Module

[Module 5.3 — pipe() and IPC Patterns](../module-05-03-pipes-ipc/README.md)
