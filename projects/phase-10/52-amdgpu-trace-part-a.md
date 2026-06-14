# Project 52 Part A: AMDGPU Trace

**Module:** 10.4 — Memory Management in Graphics Drivers  
**Curriculum project:** 52 (Part A of 2 — Part B in Phase 11)  
**Estimated time:** 12–16 hours

## Description

Trace one AMDGPU-related path through userspace (optional) and kernel DRM/amdgpu code. Document file paths and function names — **read-only**, like Phase 7 Project 40 but focused on the graphics stack.

Part B (Phase 11) will use this trace to inform a small upstream documentation or code contribution.

## Choose one trace path

| Path | Suggested chain |
|------|-----------------|
| DRM open | `open("/dev/dri/card0")` → libdrm → `drm_open` → amdgpu |
| GEM create | ioctl → `drm_ioctl` → `amdgpu_gem_create` (or equivalent for your kernel version) |
| CS / job submit | Mesa → ioctl → amdgpu scheduler (advanced; document Mesa hop if used) |

## Deliverable: `AMDGPU_TRACE.md`

### 1. Environment

- Kernel version tag
- Path A or B; Mesa version if userspace included
- Tools: local clone, Elixir, `strace` on `open /dev/dri/card0` (optional Path A)

### 2. Trace table

| Step | Function / ioctl | File path or layer |
|------|------------------|-------------------|

Minimum **10 steps** with verified kernel paths (userspace steps optional but encouraged).

### 3. Subsystem diagram

Place traced code in context: Mesa (optional) → libdrm → DRM core → amdgpu → GEM/TTM (if applicable).

### 4. MAINTAINERS

Relevant subsection for traced amdgpu/DRM files.

### 5. Documentation link

One `Documentation/gpu/` or DRM doc file; 5-line summary.

### 6. Phase 11 preview

Half page: what kind of **small** contribution Part B might target (doc fix, comment, trace improvement — no commitment yet).

## Rubric

| Criterion | Points |
|-----------|--------|
| Trace table accurate (spot-check 4 entries) | 35 |
| Subsystem diagram | 20 |
| MAINTAINERS included | 10 |
| Documentation summary | 10 |
| Phase 11 preview | 10 |
| [graphics-trace-checklist.md](../../labs/phase-10/checklists/graphics-trace-checklist.md) completed | 10 |
| Worksheet 10.4 completed | 5 |
| **Total** | **100** |

## Checklist

[labs/phase-10/checklists/graphics-trace-checklist.md](../../labs/phase-10/checklists/graphics-trace-checklist.md)

## Note

Function names vary by kernel version — document your tag and stay consistent. Exact ioctl numbers not required unless you cite them from headers.

## Next

Phase 11 — [Project 52 Part B](../phase-11/52-amdgpu-contribution-part-b.md)
