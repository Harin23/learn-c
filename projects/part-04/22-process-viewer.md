# Project 22: Process Viewer

**Module:** 4.2 — Processes and Signals  
**Estimated time:** 5–6 hours

## Description

List running processes by scanning `/proc`, similar to a minimal `ps`.

## Usage

```bash
procview                    # PID  CMD
procview --user alice       # filter by user (parse status file)
procview 1234               # details for one PID
```

## Default Output

```
  PID CMD
    1 systemd
  892 bash
 1234 procview
```

## Single PID Mode

Print from `/proc/[pid]/status`: Name, State, Pid, PPid, Uid, VmRSS.

## Requirements

- Scan `/proc` for numeric directory names
- Read `Name` and `State` from `status` or comm from `/proc/[pid]/comm`
- Skip kernel threads optionally (no cmdline and state D) — document behavior
- Handle permission denied on some PIDs gracefully

## Rubric

| Criterion | Points |
|-----------|--------|
| Lists majority of user processes | 30 |
| Single-PID detail mode | 25 |
| Permission errors handled | 15 |
| Column alignment readable | 10 |
| Zero warnings | 10 |
| README documents /proc fields used | 10 |
| **Total** | **100** |

## Starter

[labs/part-04/proc_stat_starter.c](../../labs/part-04/proc_stat_starter.c)
