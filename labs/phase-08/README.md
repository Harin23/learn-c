# Phase 8 Labs

Starter materials for kernel build, boot, trace, and patch labs. The Linux kernel source is **not** vendored in this repository — clone locally and set `KERNEL_SRC`.

## Setup

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-08.sh
```

Or run the lab script directly:

```bash
./labs/phase-08/scripts/setup-kernel-build.sh
```

## Directory Layout

| Path | Purpose |
|------|---------|
| [configs/learn-c-base.config](configs/learn-c-base.config) | Kconfig fragment (debug, ftrace) |
| [scripts/setup-kernel-build.sh](scripts/setup-kernel-build.sh) | Toolchain verification |
| [scripts/qemu-boot-test.sh.template](scripts/qemu-boot-test.sh.template) | VM boot template |
| [worksheets/](worksheets/) | Module 8.1–8.5 worksheets |
| [checklists/](checklists/) | VM safety and kernel patch review |

## Worksheets

| Worksheet | Module |
|-----------|--------|
| [8.1-boot-log-analysis.md](worksheets/8.1-boot-log-analysis.md) | 8.1 |
| [8.2-kbuild-tour.md](worksheets/8.2-kbuild-tour.md) | 8.2 |
| [8.3-coding-style-lab.md](worksheets/8.3-coding-style-lab.md) | 8.3 |
| [8.4-mm-sched-kernel-tour.md](worksheets/8.4-mm-sched-kernel-tour.md) | 8.4 |
| [8.5-locking-scavenger-hunt.md](worksheets/8.5-locking-scavenger-hunt.md) | 8.5 |

## Disk and RAM

- ~25 GB free for tree + build directory
- 8 GB RAM minimum; 16 GB recommended for `make -j$(nproc)`

## Safety

Read [checklists/vm-safety-checklist.md](checklists/vm-safety-checklist.md) before booting a custom kernel.
