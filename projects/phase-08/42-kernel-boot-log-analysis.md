# Project 42: Kernel Boot Log Analysis

**Module:** 8.1 — Kernel Architecture Overview  
**Estimated time:** 10–12 hours

## Description

Analyze kernel boot messages from your current system (host or VM) and map them to kernel subsystems and boot phases. Connect dmesg output to source locations you will build in later modules.

## Prerequisites

- Phase 7 Project 40 notes (syscall trace) for comparison
- Worksheet [8.1-boot-log-analysis.md](../../labs/phase-08/worksheets/8.1-boot-log-analysis.md)

## Deliverable: `BOOT_ANALYSIS.md`

### 1. Environment

- Host vs VM
- Kernel version: `uname -r`
- How boot log was captured (`dmesg -T`, `journalctl -k`, etc.)

### 2. Boot phase timeline

Divide boot into at least **five phases**, for example:

| Phase | Approx. time / order | Example messages |
|-------|----------------------|------------------|
| Early arch | first lines | CPU, memory map |
| Subsystem init | mid boot | scheduler, VFS, block |
| Drivers | later | PCI, storage, net |
| Late init | near end | filesystem mount |
| Userspace handoff | last kernel lines | run init |

Fill with **real lines** from your log (quote ≥10 lines total).

### 3. Subsystem mapping table

Map **≥8** log lines to subsystems (`mm/`, `fs/`, `kernel/`, `drivers/`, `init/`, etc.) with one-sentence explanation each.

### 4. Source cross-reference

For **three** messages, locate related init or printk site in `$KERNEL_SRC` (or Elixir). Table:

| Log line (abbrev) | Likely source file | Function or symbol |
|-------------------|--------------------|--------------------|

### 5. Diagram

ASCII or mermaid: boot flow from firmware to `init` with subsystem boxes.

### 6. Comparison to Project 40

Two paragraphs: how boot-time init relates to the runtime syscall path you traced in Phase 7.

## Rubric

| Criterion | Points |
|-----------|--------|
| Boot phases with real log quotes (≥10 lines) | 25 |
| Subsystem mapping (≥8 entries, accurate) | 30 |
| Source cross-reference (≥3) | 20 |
| Boot flow diagram | 15 |
| Project 40 comparison | 10 |
| **Total** | **100** |

## Worksheet

[labs/phase-08/worksheets/8.1-boot-log-analysis.md](../../labs/phase-08/worksheets/8.1-boot-log-analysis.md)

## Note

Log content varies by hardware and distro. Document your environment; do not copy generic examples without matching your machine.
