# Project 23: System Monitor

**Module:** 4.2 — Processes and Signals  
**Estimated time:** 5–6 hours

## Description

Poll system and process metrics from `/proc` on an interval; exit cleanly on SIGINT.

## Usage

```bash
sysmon              # refresh every 2 seconds
sysmon -i 1         # 1 second interval
sysmon -n 5         # 5 samples then exit
```

## Display (minimum)

```
=== sysmon ===
loadavg: 0.52 0.48 0.45
mem_total_kb: 16384000
mem_available_kb: 8192000
procs_running: 3
uptime_sec: 86400
[Ctrl+C to quit]
```

Sources:

- `/proc/loadavg`
- `/proc/meminfo` (MemTotal, MemAvailable)
- `/proc/stat` (first line cpu + btime for uptime)

## Requirements

- Install `SIGINT` handler with `sigaction`; set flag to exit main loop
- Clear screen optional (`\033[2J`) or print separator between samples
- Parse errors: print message, continue or exit based on severity

## Rubric

| Criterion | Points |
|-----------|--------|
| loadavg and meminfo parsed correctly | 30 |
| SIGINT exits cleanly (no broken terminal) | 20 |
| Interval flag works | 15 |
| `/proc/stat` uptime or cpu line used | 15 |
| Zero warnings | 10 |
| Handler is async-signal-safe | 10 |
| **Total** | **100** |

## Starter

[labs/phase-04/signal_starter.c](../../labs/phase-04/signal_starter.c)
