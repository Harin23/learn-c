# Phase 8 — Linux Kernel Fundamentals

Build, boot, observe, and patch the Linux kernel in-tree. This phase bridges Phase 7 (read-only kernel navigation) and Phase 9 (loadable kernel modules and drivers).

**Estimated time:** 75–90 hours (5 modules × 15–18 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [8.1](module-08-01-kernel-architecture-overview/README.md) | Kernel Architecture Overview | 15–18 |
| [8.2](module-08-02-kernel-build-system/README.md) | Kernel Build System | 15–18 |
| [8.3](module-08-03-kernel-subsystems-and-apis/README.md) | Kernel Subsystems and APIs | 15–18 |
| [8.4](module-08-04-kernel-mm-and-scheduling/README.md) | Kernel Memory Management and Scheduling | 15–18 |
| [8.5](module-08-05-kernel-synchronization/README.md) | Kernel Synchronization | 15–18 |

## Prerequisites

**Required:** [Phase 6 exit gate](../phase-06-computer-architecture-os/README.md#phase-exit-gate)

**Required:** [Phase 7 exit gate](../phase-07-reading-large-codebases/README.md#phase-exit-gate)

Additional packages and disk space:

```bash
sudo apt install -y bc bison flex libssl-dev libelf-dev libncurses-dev \
    rsync dwarves qemu-system-x86 ccache
```

See [docs/environment-setup.md](../docs/environment-setup.md) and run `./scripts/verify-phase-08.sh`.

**Hardware:** ≥25 GB free disk for kernel tree + build; ≥8 GB RAM (16 GB recommended for parallel builds).

**Safety:** Boot custom kernels in a VM only until you have a recovery plan. See [labs/phase-08/checklists/vm-safety-checklist.md](../labs/phase-08/checklists/vm-safety-checklist.md).

## Scope

| In this phase | Deferred to Phase 9 |
|---------------|---------------------|
| Kbuild, `.config`, VM boot | Loadable modules (`insmod`) |
| `printk`, coding style, in-tree patches | Char devices, `file_operations` |
| ftrace on `mm/` and `kernel/sched/` | Sysfs/procfs driver interfaces |
| Documentation and debug patches | PCI probe, hardware drivers |

## Phase Exit Gate

Do not start Phase 9 until you can independently:

- Build a configured Linux kernel from source and boot it in a VM without changing the host default boot entry
- Explain boot flow from firmware to `init` and map subsystems to top-level directories
- Apply kernel coding style and produce a `Signed-off-by` patch reviewed with `checkpatch.pl`
- Use ftrace (or trace-cmd) to observe scheduling or MM-related kernel activity and cite source functions
- Explain spinlock vs mutex and why sleeping in atomic context is forbidden
- Complete all Phase 8 projects (42–46) with written build/trace/patch artifacts

## Resources

See [resources/phase-08.md](../resources/phase-08.md) for the canonical reading list and pinned kernel version.

## Projects in This Phase

| # | Project | Module | Spec |
|---|---------|--------|------|
| 42 | Kernel boot log analysis | 8.1 | [42-kernel-boot-log-analysis.md](../projects/phase-08/42-kernel-boot-log-analysis.md) |
| 43 | Custom kernel build and VM boot | 8.2 | [43-custom-kernel-build-boot.md](../projects/phase-08/43-custom-kernel-build-boot.md) |
| 44 | Syscall debug patch | 8.3 | [44-syscall-debug-patch.md](../projects/phase-08/44-syscall-debug-patch.md) |
| 45 | MM or scheduler live trace | 8.4 | [45-mm-or-sched-trace.md](../projects/phase-08/45-mm-or-sched-trace.md) |
| 46 | Phase 8 capstone patch | 8.5 | [46-kernel-patch-capstone.md](../projects/phase-08/46-kernel-patch-capstone.md) |

Set `KERNEL_SRC` to your local kernel tree (reuse Phase 7 clone if present):

```bash
export KERNEL_SRC="$HOME/src/linux"
```
