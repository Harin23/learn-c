# Module 5.3 — pipe() and IPC Patterns

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Connect two processes with anonymous pipes
- Redirect stdin/stdout with `dup2`
- Build shell pipelines: `cmd1 | cmd2`
- Understand pipe capacity and blocking behavior
- Combine fork + pipe + exec for filter chains

## Prerequisites

- Completed [Module 5.2](../module-05-02-fork-exec/README.md) exit criteria

## Concepts to Study

1. **`pipe(2)`** — two fds: read end, write end; unidirectional
2. **`dup2(2)`** — duplicate fd onto stdin/stdout/stderr slot
3. **Pipeline pattern** — fork child1 writes pipe, fork child2 reads pipe
4. **Closing unused ends** — prevent deadlock; reader blocks if writer fd open
5. **Shell and `/bin/sh -c`** — optional delegation vs hand-built pipelines
6. **FIFO preview** — named pipes for unrelated processes
7. **`popen(3)`** — convenience wrapper; know what it does internally

## Hands-On Labs

### Lab 1: Parent-Child Pipe

Parent writes message; child reads and prints.

Starter: [labs/phase-05/pipe_fork_starter.c](../../labs/phase-05/pipe_fork_starter.c)

### Lab 2: dup2 Redirect

Redirect stdout to pipe or file; run printf; verify reader receives output.

Starter: [labs/phase-05/dup2_starter.c](../../labs/phase-05/dup2_starter.c)

### Lab 3: Two-Process Pipeline

Implement `equivalent of: cat file | wc -l` using fork, pipe, dup2, exec.

### Lab 4: strace Pipeline

Trace your shell running `echo hello | wc -c`. Compare to hand-built pipeline syscalls.

## Mini-Project

**Pipe Filter Pipeline** — [projects/phase-05/28-pipe-pipeline.md](../../projects/phase-05/28-pipe-pipeline.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 2 pipe`, `man 2 dup2` | Primary |
| APUE Ch. 15 | Pipes |
| Project 27 shell | Add `|` support as extension |

## Exit Criteria

Before advancing to Module 5.4, confirm:

- [ ] Pipe fork lab works without deadlock
- [ ] Pipeline project runs two-stage filter correctly
- [ ] All unused pipe fds closed in every code path
- [ ] You can draw fd layout for `A | B` with two children

## Next Module

[Module 5.4 — pthreads (Advanced)](../module-05-04-pthreads-advanced/README.md)
