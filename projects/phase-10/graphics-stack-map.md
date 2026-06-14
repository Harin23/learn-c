# Report: Graphics Stack Map

**Module:** 10.1 — Linux Graphics Stack Overview  
**Estimated time:** 10–12 hours

## Description

Document the Linux graphics stack from an application down to AMD GPU hardware. Include live sysfs/device node observations if hardware is available, or a source-only research path if not.

## Prerequisites

- Worksheet [10.1-graphics-stack-tour.md](../../labs/phase-10/worksheets/10.1-graphics-stack-tour.md)

## Deliverable: `GRAPHICS_STACK.md`

### 1. Environment

- Path A (AMD hardware) or Path B (source-only)
- Kernel version / distro if hardware present
- Tools used (`glxinfo`, sysfs, Elixir)

### 2. Stack table

| Layer | Component | Example path or library | Role (1–2 sentences) |
|-------|-----------|-------------------------|----------------------|
| Application | | | |
| API | OpenGL/Vulkan/EGL | | |
| Userspace driver | Mesa | | |
| DRM library | libdrm | | |
| Kernel framework | DRM core | `drivers/gpu/drm/` | |
| Device driver | amdgpu | `drivers/gpu/drm/amd/amdgpu/` | |
| Hardware | AMD GPU | PCI / `/sys/class/drm/` | |

Minimum **6 rows** filled with substance.

### 3. Live observation (Path A) or documented N/A (Path B)

Paste `ls /dev/dri/` and `ls /sys/class/drm/` output **or** explain why unavailable and what you used instead.

### 4. Diagram

ASCII or mermaid: data flow for one frame of rendering or one ioctl path (high level).

### 5. Phase connections

One paragraph each linking to Phase 6 (`/sys/class/drm`) and Phase 9 (PCI/display driver binding).

## Rubric

| Criterion | Points |
|-----------|--------|
| Stack table complete and accurate | 35 |
| Live observation or honest Path B alternative | 20 |
| Diagram shows user/kernel boundary | 20 |
| Phase 6/9 connections | 15 |
| Worksheet 10.1 completed | 10 |
| **Total** | **100** |

## Note

Do not build Mesa or kernel modules for this report.
