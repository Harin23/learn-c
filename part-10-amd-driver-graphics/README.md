# Part 10 — AMD Driver and Graphics Stack Exploration

Read-only exploration of the Linux graphics stack: user space, Mesa, DRM, and AMDGPU kernel driver. Analysis and trace reports only — no kernel modules, Mesa builds, or upstream patches (those are Part 11).

**Estimated time:** 50–65 hours (4 modules × 12–15 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [10.1](module-10-01-graphics-stack-overview/README.md) | Linux Graphics Stack Overview | 12–15 |
| [10.2](module-10-02-drm-amdgpu-architecture/README.md) | DRM Subsystem and AMDGPU Architecture | 12–15 |
| [10.3](module-10-03-mesa-gpu-scheduling/README.md) | Mesa Overview and GPU Scheduling | 12–15 |
| [10.4](module-10-04-gem-ttm-memory/README.md) | Memory Management in Graphics Drivers | 12–15 |

## Prerequisites

**Required:** [Part 9 exit gate](../part-09-kernel-modules-drivers/README.md#part-exit-gate)

**Required:** [Part 8 exit gate](../part-08-linux-kernel-fundamentals/README.md#part-exit-gate) (kernel source literacy, `$KERNEL_SRC`)

**Recommended:** Part 7 Project 40 (syscall trace) and Part 6 Module 6.5 (`/sys/class/drm` preview)

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-part-10.sh
```

**Hardware:** AMD GPU with `amdgpu` (Path A) is recommended but **not required**. Path B uses Elixir Bootlin + `$KERNEL_SRC` only — mark reports when hardware is N/A.

Optional packages: `mesa-utils`, `vulkan-tools` — see [docs/environment-setup.md](../docs/environment-setup.md).

## Scope

| In this part | Deferred to Part 11 |
|---------------|----------------------|
| Graphics stack map, DRM/AMDGPU source reading | Patch submission workflow |
| Mesa role (conceptual browse) | Signed-off-by upstream contribution |
| GEM/TTM analysis | Maintainer review cycles |
| Project 52 Part A — AMDGPU trace | Project 52 Part B — contribution |

## Part Exit Gate

Do not start Part 11 until you can independently:

- Explain Linux graphics stack layers from application to AMD hardware
- Navigate `drivers/gpu/drm/amd/amdgpu/` and cite key source files
- Describe Mesa's role and one userspace-to-kernel boundary
- Explain GEM/TTM and VRAM vs GTT at a conceptual level
- Complete all four module reports and **Project 52 Part A** (`AMDGPU_TRACE.md`)
- **Not required for exit:** AMD hardware, building Mesa, or kernel patches

## Resources

See [resources/part-10.md](../resources/part-10.md) for the canonical reading list.

## Projects and Reports in This Part

| Deliverable | Module | Spec | Output |
|-------------|--------|------|--------|
| Graphics stack map | 10.1 | [graphics-stack-map.md](../projects/part-10/graphics-stack-map.md) | `GRAPHICS_STACK.md` |
| DRM/AMDGPU architecture walk | 10.2 | [drm-amdgpu-architecture.md](../projects/part-10/drm-amdgpu-architecture.md) | `DRM_AMDGPU_WALK.md` |
| Mesa/GPU scheduling path | 10.3 | [mesa-gpu-scheduling.md](../projects/part-10/mesa-gpu-scheduling.md) | `MESA_GPU_PATH.md` |
| GEM/TTM analysis | 10.4 | [gem-ttm-memory.md](../projects/part-10/gem-ttm-memory.md) | `GEM_TTM_ANALYSIS.md` |
| **Project 52 Part A** | 10.4 | [52-amdgpu-trace-part-a.md](../projects/part-10/52-amdgpu-trace-part-a.md) | `AMDGPU_TRACE.md` |

Project 52 Part B (upstream contribution) completes in [Part 11](../part-11-open-source-contributions/).
