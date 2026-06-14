# Report: DRM and AMDGPU Architecture Walk

**Module:** 10.2 — DRM Subsystem and AMDGPU Architecture  
**Estimated time:** 12–14 hours

## Description

Walk through DRM core and AMDGPU driver source layout. Document key files, driver registration, and a short read-only trace from opening `/dev/dri/card0` toward `drm_ioctl`.

## Prerequisites

- `$KERNEL_SRC` or Elixir at pinned tag ([resources/part-10.md](../../resources/part-10.md))
- Worksheet [10.2-drm-amdgpu-tree.md](../../labs/part-10/worksheets/10.2-drm-amdgpu-tree.md)

## Deliverable: `DRM_AMDGPU_WALK.md`

### 1. Environment

- Kernel tag (e.g. v6.12)
- Browse tool: local clone vs Elixir URL

### 2. File inventory

| File path | Primary purpose |
|-----------|-----------------|

Minimum **8 entries** under `drivers/gpu/drm/` and/or `drivers/gpu/drm/amd/amdgpu/`.

### 3. Driver registration

Where amdgpu registers with DRM/PCI (file, function names, 1 paragraph).

### 4. Short trace (open → ioctl dispatch)

| Step | Function | File path |
|------|----------|-----------|

Minimum **5 steps** (open path or `DRM_IOCTL_INFO` — document choice).

### 5. MAINTAINERS

Paste relevant MAINTAINERS subsection for DRM or amdgpu.

### 6. Comparison to VFS

Two paragraphs: DRM file ops vs regular file read path (Part 7 Project 40).

## Rubric

| Criterion | Points |
|-----------|--------|
| File inventory (≥8, accurate roles) | 30 |
| Driver registration explained | 15 |
| Trace table (≥5 steps, verified paths) | 25 |
| MAINTAINERS included | 10 |
| VFS comparison | 10 |
| Worksheet 10.2 completed | 10 |
| **Total** | **100** |
