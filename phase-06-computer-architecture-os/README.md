# Phase 6 — Computer Architecture and Operating Systems

Connect your systems programming skills to how hardware and the Linux kernel actually work: CPUs, virtual memory, scheduling, filesystems, caches, and interrupts. This phase is required before kernel development (Phase 8).

**Estimated time:** 70–85 hours (5 modules × 14–17 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [6.1](module-06-01-cpu-architecture/README.md) | CPU Architecture and Instruction Execution | 14–17 |
| [6.2](module-06-02-virtual-memory/README.md) | Memory Hierarchy and Virtual Memory | 14–17 |
| [6.3](module-06-03-scheduling/README.md) | Scheduling and Context Switching | 14–17 |
| [6.4](module-06-04-filesystems/README.md) | Filesystems and I/O Subsystems | 14–17 |
| [6.5](module-06-05-drivers-interrupts-caches/README.md) | Device Drivers, Interrupts, and Caches | 14–17 |

## Prerequisites

Complete [Phase 5 exit gate](../phase-05-linux-systems-programming/README.md#phase-exit-gate) (may overlap with late Phase 5 modules).

Phase 7 (Reading Large Codebases) can run in parallel after Phase 5, but **Phase 8 requires both Phase 6 and Phase 7**.

Additional packages:

```bash
sudo apt install -y binutils linux-tools-common
# Optional: perf for Module 6.5
sudo apt install -y linux-tools-generic
```

## Phase Exit Gate

Do not start Phase 8 until you can independently:

- Read x86-64 assembly for simple C functions and explain calling conventions at a high level
- Interpret `/proc/[pid]/maps` and explain virtual vs physical memory
- Describe page tables, TLB, and demand paging conceptually
- Implement a discrete-event CPU scheduler simulation and explain preemptive scheduling
- Explain inodes, dentry cache, and block I/O path for a file read
- Measure cache effects empirically and explain interrupt-driven I/O model
- Complete all Phase 6 projects (34–38) with written analysis documents

## Resources

See [resources/phase-06.md](../resources/phase-06.md) for the canonical reading list.

## Projects in This Phase

| # | Project | Module | Spec |
|---|---------|--------|------|
| 34 | Assembly and register trace | 6.1 | [34-assembly-trace.md](../projects/phase-06/34-assembly-trace.md) |
| 35 | Virtual memory map explorer | 6.2 | [35-vm-map-explorer.md](../projects/phase-06/35-vm-map-explorer.md) |
| 36 | CPU scheduler simulator | 6.3 | [36-scheduler-simulator.md](../projects/phase-06/36-scheduler-simulator.md) |
| 37 | Inode and filesystem lab | 6.4 | [37-inode-filesystem-lab.md](../projects/phase-06/37-inode-filesystem-lab.md) |
| 38 | Cache and interrupt analysis | 6.5 | [38-cache-interrupt-analysis.md](../projects/phase-06/38-cache-interrupt-analysis.md) |
