# Module 10.1 — Linux Graphics Stack Overview

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe the graphics stack from application to GPU hardware
- Explain roles of Mesa/Vulkan/OpenGL, libdrm, kernel DRM, and `amdgpu`
- Navigate `/dev/dri/` and `/sys/class/drm/` on AMD hardware or document source-only alternatives
- Connect Part 6 `/sys/class/drm` lab and Part 9 PCI/display binding concepts

## Prerequisites

- [Part 9 exit gate](../../part-09-kernel-modules-drivers/README.md#part-exit-gate)
- `$KERNEL_SRC` available (same tag as Part 8/9)

## Concepts to Study

1. **Application** — OpenGL/Vulkan/EGL client
2. **Mesa** — userspace driver implementation (Part 10.3 deepens)
3. **libdrm** — userspace DRM library; ioctl wrapper
4. **Kernel DRM** — generic display/GPU framework in `drivers/gpu/drm/`
5. **AMDGPU** — AMD-specific kernel driver under `drm/amd/amdgpu/`
6. **`/dev/dri/cardN`** — DRM device nodes
7. **`/sys/class/drm/`** — connectors, modes, device sysfs
8. **Display vs render** — `card0` vs `renderD128` distinction (high level)

## Hands-On Labs

### Lab 1: Sysfs and Device Nodes

On AMD host (Path A) or skip with note (Path B):

```bash
ls -la /dev/dri/
ls /sys/class/drm/
cat /sys/class/drm/card0/device/uevent 2>/dev/null || echo "hardware N/A"
```

### Lab 2: Optional User-Space Info

If `mesa-utils` installed:

```bash
glxinfo -B | head -20
vulkaninfo --summary 2>/dev/null | head -20
```

### Lab 3: Graphics Stack Worksheet

Worksheet: [labs/part-10/worksheets/10.1-graphics-stack-tour.md](../../labs/part-10/worksheets/10.1-graphics-stack-tour.md)

### Lab 4: Stack Diagram

Draw user → Mesa → libdrm → ioctl → DRM core → amdgpu → hardware (ASCII or mermaid).

## Module Report

**Graphics Stack Map** — [projects/part-10/graphics-stack-map.md](../../projects/part-10/graphics-stack-map.md)

Deliverable: `GRAPHICS_STACK.md`

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/part-10.md](../../resources/part-10.md) | Reading map |
| `Documentation/gpu/` | Kernel GPU docs index |
| Part 6 [Module 6.5](../../part-06-computer-architecture-os/module-06-05-drivers-interrupts-caches/README.md) | `/sys/class` preview |

## Exit Criteria

Before advancing to Module 10.2, confirm:

- [ ] Worksheet 10.1 completed
- [ ] Can name each stack layer and its primary responsibility
- [ ] `GRAPHICS_STACK.md` submitted (Path A or B documented)
- [ ] Diagram includes kernel vs userspace boundary

## Next Module

[Module 10.2 — DRM Subsystem and AMDGPU Architecture](../module-10-02-drm-amdgpu-architecture/README.md)
