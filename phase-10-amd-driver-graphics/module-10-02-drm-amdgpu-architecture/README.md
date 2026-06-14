# Module 10.2 — DRM Subsystem and AMDGPU Architecture

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Distinguish DRM core code from AMDGPU driver code
- Tour `drivers/gpu/drm/` and `drivers/gpu/drm/amd/amdgpu/` in `$KERNEL_SRC`
- Explain `drm_device`, driver registration, and file operations leading to `drm_ioctl`
- Locate AMDGPU module init and MAINTAINERS entries
- Trace one read-only entry point (e.g. DRM file open or `DRM_IOCTL_INFO`)

## Prerequisites

- Completed [Module 10.1](../module-10-01-graphics-stack-overview/README.md) exit criteria

## Concepts to Study

1. **DRM core** — shared infrastructure: `drm_drv.c`, ioctl dispatch
2. **Driver hook** — `struct drm_driver`, `drm_dev_register`
3. **AMDGPU layout** — `amdgpu_drv.c`, `amdgpu_device.c`, `amdgpu_kms.c` (names may vary by version)
4. **File ops** — `drm_open`, `drm_ioctl` path from `/dev/dri/card0`
5. **KMS** — kernel mode setting preview (connectors, CRTCs)
6. **PCI binding** — amdgpu as PCI driver (Phase 9 connection)
7. **MAINTAINERS** — `drivers/gpu/drm/` mailing lists
8. **Elixir Bootlin** — browse when local clone slow

## Hands-On Labs

### Lab 1: Top-Level Tree Tour

In `$KERNEL_SRC` or Elixir, list files in:

- `drivers/gpu/drm/`
- `drivers/gpu/drm/amd/amdgpu/` (first 20 files)

Worksheet: [labs/phase-10/worksheets/10.2-drm-amdgpu-tree.md](../../labs/phase-10/worksheets/10.2-drm-amdgpu-tree.md)

### Lab 2: Find Driver Init

Locate amdgpu driver registration (`module_init`, `amdgpu_init`, or `amdgpu_driver_kms` — document your kernel version's symbol).

### Lab 3: Compare to Phase 7 VFS Trace

Two paragraphs: how opening `/dev/dri/card0` differs from opening a regular file (Phase 7 Project 40).

### Lab 4: MAINTAINERS Scavenger Hunt

Copy MAINTAINERS subsection for `drivers/gpu/drm/amd/` or DRM core.

## Module Report

**DRM/AMDGPU Architecture Walk** — [projects/phase-10/drm-amdgpu-architecture.md](../../projects/phase-10/drm-amdgpu-architecture.md)

Deliverable: `DRM_AMDGPU_WALK.md`

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/gpu/` | Kernel GPU documentation |
| [Elixir Bootlin](https://elixir.bootlin.com/linux/v6.12/source/drivers/gpu/drm) | Online browse |
| Phase 7 [Project 40](../../projects/phase-07/40-kernel-subsystem-trace.md) | Trace format |

## Exit Criteria

Before advancing to Module 10.3, confirm:

- [ ] Worksheet 10.2 completed with ≥8 files and roles
- [ ] MAINTAINERS subsection included in report
- [ ] `DRM_AMDGPU_WALK.md` complete
- [ ] One ioctl or open path outlined (≥5 steps)

## Next Module

[Module 10.3 — Mesa Overview and GPU Scheduling](../module-10-03-mesa-gpu-scheduling/README.md)
