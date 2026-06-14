# Project 28: Pipe Filter Pipeline

**Module:** 5.3 — pipe() and IPC Patterns  
**Estimated time:** 6–8 hours

## Description

Implement a mini pipeline runner: `ppl 'cmd1 args' 'cmd2 args'` connecting stdout of first to stdin of second via pipe, fork, dup2, and exec.

## Usage

```bash
ppl 'grep error' 'wc -l' < server.log
ppl 'cat file.txt' 'tr a-z A-Z'
```

## Requirements

- Parse exactly two command strings (use `/bin/sh -c` **not allowed** — build argv yourself or use simple split)
- Create pipe; fork twice:
  - Child 1: dup2 pipe write → stdout; close unused; exec cmd1
  - Child 2: dup2 pipe read → stdin; close unused; exec cmd2
- Parent closes both pipe ends; `waitpid` both children
- Return exit status of second command (pipeline convention)

## Error Handling

- Either exec failure: perror in child, `_exit(127)`
- Pipe or fork failure in parent: perror, exit 1

## Rubric

| Criterion | Points |
|-----------|--------|
| Two-stage pipeline works | 35 |
| dup2 and fd hygiene correct | 25 |
| waitpid both children | 15 |
| Matches shell for test cases | 15 |
| Zero warnings + README fd diagram | 10 |
| **Total** | **100** |

## Test Cases

```bash
echo -e "a\nb\na" | ./ppl 'grep a' 'wc -l'    # expect 2
./ppl 'cat /etc/hostname' 'wc -c'
```

## Starter

[labs/phase-05/pipe_fork_starter.c](../../labs/phase-05/pipe_fork_starter.c)
