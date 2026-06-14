# Project 33: Process Manager (Part 5 Capstone)

**Module:** 5.6 — Event-Driven Programming  
**Estimated time:** 8–10 hours

## Description

Interactive process manager combining `/proc` reading, `fork`/`exec`, signals, and an event-driven refresh loop.

## Usage

```bash
procmgr
> list
> run sleep 100
> signal 12345 TERM
> wait 12345
> refresh
> quit
```

## Commands

| Command | Action |
|---------|--------|
| `list` | Print PID, STAT, CMD from `/proc` (reuse Part 4 procview logic) |
| `run prog [args...]` | fork + exec background child; track in job table |
| `signal pid SIG` | send SIGTERM, SIGINT, or SIGKILL by name |
| `wait pid` | waitpid specific child |
| `refresh` | update display (or auto-refresh every N sec with poll timeout) |
| `quit` | SIGTERM tracked children, wait, exit |

## Requirements

- Track spawned children in a table (max 32)
- Reap zombies on SIGCHLD (handler sets flag; main loop reaps — async-signal-safe)
- `select`/`poll` with timeout for interactive input + periodic refresh
- strace appendix in README for one `run` command

## Rubric

| Criterion | Points |
|-----------|--------|
| list shows processes | 20 |
| run fork/exec works | 25 |
| signal sends to pid | 15 |
| SIGCHLD reaping | 20 |
| Event loop / refresh | 10 |
| Zero warnings + strace notes | 10 |
| **Total** | **100** |

## Part 5 Completion

Passing this project (≥80 points) plus Projects 27–32 completes Part 5.

## Starter

Combine [proc_stat_starter.c](../../labs/part-04/proc_stat_starter.c) patterns with [fork_starter.c](../../labs/part-05/fork_starter.c)
