# Project 27: Custom Shell

**Module:** 5.2 — fork() and exec()  
**Estimated time:** 8–10 hours

## Description

Build a minimal interactive Unix shell that reads commands, forks, execs external programs, and waits for completion.

## Usage

```bash
myshell
mysh$ ls -la
mysh$ cd /tmp
mysh$ pwd
mysh$ exit
```

## Requirements

### Parsing

- Read line with prompt `myshell$ ` (or configurable)
- Split into argv (max 128 args); handle extra whitespace
- Empty line: no-op

### Builtins (execute in shell process, no fork)

| Command | Behavior |
|---------|----------|
| `exit` | quit shell |
| `cd dir` | `chdir(2)`; error with perror |
| `pwd` | print cwd with `getcwd` |

### External commands

- `fork` + `execvp` + `waitpid`
- Preserve stdin/stdout/stderr attached to terminal
- Print non-zero exit status: `command exited with status N`

### Optional extensions (rubric bonus)

- `|` pipeline of two commands (Module 5.3 integration)
- Background `&` with job list preview
- History with up-arrow (termios — hard; optional)

## Rubric

| Criterion | Points |
|-----------|--------|
| External commands via execvp | 30 |
| cd, pwd, exit builtins | 25 |
| waitpid reaps children (no zombies) | 20 |
| Line parsing robust | 10 |
| strace notes in README | 5 |
| Zero warnings | 10 |
| **Total** | **100** |

## strace Requirement

Include in README: paste of `strace -e trace=process,wait ./myshell` for running `echo hi`.

## Starters

[labs/part-05/fork_starter.c](../../labs/part-05/fork_starter.c), [exec_starter.c](../../labs/part-05/exec_starter.c)
