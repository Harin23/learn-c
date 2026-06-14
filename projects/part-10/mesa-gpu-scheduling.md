# Report: Mesa and GPU Scheduling Path

**Module:** 10.3 — Mesa Overview and GPU Scheduling  
**Estimated time:** 10–12 hours

## Description

Explain Mesa's role in the graphics stack, outline its AMD-related source layout, and compare CPU scheduling (Part 6) to GPU command submission at a high level.

## Prerequisites

- Completed `DRM_AMDGPU_WALK.md` or in progress
- Worksheet [10.3-mesa-scheduling.md](../../labs/part-10/worksheets/10.3-mesa-scheduling.md)

## Deliverable: `MESA_GPU_PATH.md`

### 1. Mesa overview

Three paragraphs: what Mesa implements, why it is separate from kernel amdgpu, who consumes it (distro stack).

### 2. Source layout (read-only)

| Path under Mesa tree | Purpose |
|----------------------|---------|

Minimum **5 paths** (e.g. `src/amd/`, Gallium driver dirs — names for your browse version).

### 3. Userspace → kernel boundary

One diagram or table: Mesa/winsys call → libdrm → ioctl → kernel amdgpu handler (name ioctl category or function if known).

### 4. GPU scheduling (conceptual)

Explain rings/fences/command submission in plain language (no hardware manual required). Two paragraphs.

### 5. Part 6 comparison

Compare Part 6 scheduler simulator / CFS concepts to GPU queue scheduling — what is similar, what differs.

### 6. Documentation links

Two URLs from Mesa docs or wiki with one-line summary each.

## Rubric

| Criterion | Points |
|-----------|--------|
| Mesa overview accurate | 25 |
| Source layout table (≥5) | 20 |
| Userspace/kernel boundary clear | 25 |
| GPU scheduling + Part 6 comparison | 20 |
| Worksheet 10.3 completed | 10 |
| **Total** | **100** |

## Do not

- Build Mesa from source
- Submit patches to Mesa in this report (Part 11)
