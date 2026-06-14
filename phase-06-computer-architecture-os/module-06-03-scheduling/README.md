# Module 6.3 — Scheduling and Context Switching

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain preemptive vs cooperative scheduling
- Describe process states: running, ready, blocked
- Understand context switch: save/restore registers and switch address space
- Compare scheduling algorithms: FCFS, SJF, round-robin, priority
- Implement a discrete-event scheduler simulation
- Relate simulation to Linux CFS at high level (preview)

## Prerequisites

- Completed [Module 6.2](../module-06-02-virtual-memory/README.md) exit criteria

## Concepts to Study

1. **CPU scheduling goal** — maximize utilization, minimize latency/turnaround
2. **Context switch cost** — kernel saves state; cache cold after switch
3. **Time slice (quantum)** — round-robin preempts after quantum expires
4. **Blocking** — I/O wait removes from run queue
5. **Metrics** — turnaround time, waiting time, response time
6. **Linux CFS preview** — vruntime, red-black tree of tasks (read only)
7. **`/proc/schedstat`** — optional observation
8. **Real-time policies** — SCHED_FIFO mention

## Hands-On Labs

### Lab 1: Observe Context Switches

```bash
grep ctxt /proc/self/status
sleep 1
grep ctxt /proc/self/status
# run busy loop in another terminal; compare
```

### Lab 2: chrt and nice preview

```bash
nice -n 10 ./busy &
chrt -p $(pgrep busy)
```

Document what changed (priority/nice).

### Lab 3: FCFS Simulator Skeleton

Complete FCFS queue for given burst times.

Starter: [labs/phase-06/sched_fcfs_starter.c](../../labs/phase-06/sched_fcfs_starter.c)

### Lab 4: Round-Robin Extension

Add quantum to FCFS starter; compare average waiting time.

## Mini-Project

**CPU Scheduler Simulator** — [projects/phase-06/36-scheduler-simulator.md](../../projects/phase-06/36-scheduler-simulator.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| OS textbooks — scheduling chapter | FCFS, RR, MLFQ preview |
| `man 7 sched` | Linux scheduling overview |
| Linux kernel `kernel/sched/` | Phase 7–8 reading target |

## Exit Criteria

Before advancing to Module 6.4, confirm:

- [ ] Simulator implements FCFS and round-robin
- [ ] Written comparison of average waiting times on same workload
- [ ] Can explain what happens on context switch (registers + mm)
- [ ] Project 36 complete with metrics table

## Next Module

[Module 6.4 — Filesystems and I/O Subsystems](../module-06-04-filesystems/README.md)
