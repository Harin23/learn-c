# Phase 7 — Reading Large Codebases

Learn to navigate unfamiliar C codebases, understand the Linux kernel source tree, and contribute small fixes using documentation-driven development. This phase is required before kernel development (Phase 8).

**Estimated time:** 35–45 hours (3 modules × 12–15 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [7.1](module-07-01-navigating-repos/README.md) | Navigating Open-Source Repositories | 12–15 |
| [7.2](module-07-02-linux-source-tree/README.md) | Linux Source Tree Structure | 12–15 |
| [7.3](module-07-03-docs-and-small-fixes/README.md) | Documentation-Driven Development and Small Fixes | 12–15 |

## Prerequisites

**Required:** [Phase 5 exit gate](../phase-05-linux-systems-programming/README.md#phase-exit-gate)

**Required before Phase 8:** [Phase 6 exit gate](../phase-06-computer-architecture-os/README.md#phase-exit-gate) (can run in parallel with Phase 7)

Additional tools:

```bash
sudo apt install -y cscope global ripgrep universal-ctags git
```

Optional: `bear` for compile_commands.json, `git-extras`

## Phase Exit Gate

Do not start Phase 8 until you can independently:

- Clone and build an unfamiliar open-source C project using its documented workflow
- Use ripgrep, ctags/cscope, and `git log`/`git blame` to trace code paths
- Navigate the Linux kernel source tree and locate major subsystems
- Follow a syscall from entry to a kernel subsystem handler (read-only trace)
- Read `Documentation/` and code comments to infer design intent
- Produce a valid unified diff patch fixing a real bug or improving docs
- Complete all Phase 7 projects (39–41) with written exploration reports

## Resources

See [resources/phase-07.md](../resources/phase-07.md) for the canonical reading list.

## Projects in This Phase

| # | Project | Module | Spec |
|---|---------|--------|------|
| 39 | User-space codebase archaeology | 7.1 | [39-userspace-archaeology.md](../projects/phase-07/39-userspace-archaeology.md) |
| 40 | Kernel subsystem trace | 7.2 | [40-kernel-subsystem-trace.md](../projects/phase-07/40-kernel-subsystem-trace.md) |
| 41 | Small patch submission | 7.3 | [41-small-patch-submission.md](../projects/phase-07/41-small-patch-submission.md) |

Practice repository for Project 41: [labs/phase-07/mini-util/](../../labs/phase-07/mini-util/)
