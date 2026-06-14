# Module 8.1 — Kernel Architecture Overview

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe the monolithic Linux kernel model and user vs kernel space
- Explain the boot chain: firmware → bootloader → `start_kernel` → userspace `init`
- Distinguish execution contexts: process, kernel thread, interrupt (preview)
- Map Part 6 concepts (VM, scheduling, VFS) to kernel top-level directories
- Relate Part 7 Project 40 syscall trace to architecture entry code in `arch/x86/`

## Prerequisites

- [Part 6 exit gate](../../part-06-computer-architecture-os/README.md#part-exit-gate)
- [Part 7 exit gate](../../part-07-reading-large-codebases/README.md#part-exit-gate)
- Completed Project 40 (kernel subsystem trace) or equivalent notes

## Concepts to Study

1. **Monolithic kernel** — most services in one image; loadable modules (Part 9 preview)
2. **Privilege rings** — user (ring 3) vs kernel (ring 0) on x86-64
3. **Boot chain** — UEFI/BIOS, bootloader (GRUB/systemd-boot), compressed kernel, early init
4. **`start_kernel`** — C entry after arch setup; subsystems initialize in order
5. **Execution context** — process context vs interrupt context (sleep rules preview)
6. **Subsystem map** — `kernel/`, `mm/`, `fs/`, `drivers/`, `arch/`, `init/`
7. **Syscall entry** — revisit `arch/x86/entry/` path from Part 7
8. **dmesg / kernel log** — boot messages as a subsystem timeline

## Hands-On Labs

### Lab 1: Boot Log Dissection

On your host (or VM), capture boot messages:

```bash
dmesg -T | head -80
journalctl -k -b | head -80   # if systemd
```

Worksheet: [labs/part-08/worksheets/8.1-boot-log-analysis.md](../../labs/part-08/worksheets/8.1-boot-log-analysis.md)

### Lab 2: Locate Boot Entry in Source

In `$KERNEL_SRC` (or Elixir), find:

- `start_kernel` in `init/main.c`
- `rest_init`, `kernel_init` in the same file
- One `__init` function in a subsystem you care about (e.g. `mm/` or `fs/`)

Record file paths and one-line purpose each.

### Lab 3: Syscall Entry Revisit

Compare your Project 40 trace to `arch/x86/entry/common.c` (or current equivalent). Note where user registers become kernel arguments.

### Lab 4: Subsystem Interaction Diagram

Draw how a file read touches `fs/`, `mm/` (page cache), and `block/` or `drivers/` (block device). ASCII or mermaid.

## Mini-Project

**Kernel Boot Log Analysis** — [projects/part-08/42-kernel-boot-log-analysis.md](../../projects/part-08/42-kernel-boot-log-analysis.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/part-08.md](../../resources/part-08.md) | Pinned kernel version |
| *Linux Kernel Development* (Love) Ch. 2 | Boot and architecture overview |
| `Documentation/admin-guide/README.rst` | Kernel docs index |
| Part 7 [Project 40](../../projects/part-07/40-kernel-subsystem-trace.md) | Syscall trace baseline |

## Exit Criteria

Before advancing to Module 8.2, confirm:

- [ ] Worksheet 8.1 completed with ≥5 dmesg lines mapped to subsystems
- [ ] Can explain boot phases from firmware to `init` at a high level
- [ ] Located `start_kernel` and two related init functions in source
- [ ] Project 42 `BOOT_ANALYSIS.md` complete

## Next Module

[Module 8.2 — Kernel Build System](../module-08-02-kernel-build-system/README.md)
