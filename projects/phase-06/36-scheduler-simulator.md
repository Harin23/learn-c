# Project 36: CPU Scheduler Simulator

**Module:** 6.3 — Scheduling and Context Switching  
**Estimated time:** 7–8 hours

## Description

Discrete-event simulator for CPU scheduling algorithms. Input: list of processes with arrival time and CPU burst. Output: timeline and metrics.

## Input Format

```
# arrival burst
0 8
1 4
2 9
3 5
```

## Algorithms (implement all three)

| Flag | Algorithm |
|------|-----------|
| `--fcfs` | First-Come First-Served |
| `--rr Q` | Round-Robin quantum Q |
| `--sjf` | Shortest Job First (non-preemptive) |

## Output

```
time 0: P1 running
time 8: P1 done
...
--- metrics ---
PID  turnaround  waiting  response
1    8           0        0
...
avg_waiting: 6.25
```

Definitions:

- **Turnaround** = completion − arrival
- **Waiting** = turnaround − burst
- **Response** = first run − arrival

## Rubric

| Criterion | Points |
|-----------|--------|
| FCFS correct | 25 |
| Round-robin correct (test quantum=2) | 30 |
| SJF correct | 20 |
| Metrics match hand-calculated sample | 15 |
| Zero warnings + README | 10 |
| **Total** | **100** |

## Test File

[labs/phase-06/testdata/processes.txt](../../labs/phase-06/testdata/processes.txt)

## Starter

[labs/phase-06/sched_fcfs_starter.c](../../labs/phase-06/sched_fcfs_starter.c)

## Written Component

`ANALYSIS.md`: which algorithm best for interactive systems and why (2 paragraphs).
