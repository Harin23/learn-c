# Phase 10 — AMD Driver and Graphics Stack Exploration

**Status:** Coming soon — module content will be expanded after Phase 9 review.

**Estimated time:** 50–65 hours (4 modules)

## Planned Modules

| Module | Title | Hours |
|--------|-------|-------|
| 10.1 | Linux Graphics Stack Overview | 12–15 |
| 10.2 | DRM Subsystem and AMDGPU Architecture | 12–15 |
| 10.3 | Mesa Overview and GPU Scheduling | 12–15 |
| 10.4 | Memory Management in Graphics Drivers | 12–15 |

## Prerequisites

Complete [Phase 9 exit gate](../phase-09-kernel-modules-drivers/README.md#phase-exit-gate):

- Out-of-tree modules build and load in Phase 8 VM
- Char device with `copy_to_user` / `copy_from_user`
- Sysfs module attributes with clean unload
- PCI driver analysis and skeleton module
- Phase 9 capstone (Project 51)

Also requires [Phase 8 exit gate](../phase-08-linux-kernel-fundamentals/README.md#phase-exit-gate) (custom VM kernel).

## Projects (planned)

Read and analyze AMDGPU code, trace graphics driver execution, small documentation and code contributions.
