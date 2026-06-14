# Phase 10 Resources

Canonical reading list for Phase 10 — AMD Driver and Graphics Stack Exploration.

## Pinned Kernel Version

Use the same tag as Phases 8–9 ([resources/phase-08.md](phase-08.md)):

| Item | Value |
|------|-------|
| Recommended tag | `v6.12` |
| AMDGPU tree | `$KERNEL_SRC/drivers/gpu/drm/amd/amdgpu/` |
| Elixir | [elixir.bootlin.com/linux/v6.12/source/drivers/gpu/drm](https://elixir.bootlin.com/linux/v6.12/source/drivers/gpu/drm) |

```bash
export KERNEL_SRC="$HOME/src/linux"
```

## Hardware Paths

| Path | Requirements |
|------|----------------|
| **A** | AMD GPU, `amdgpu` driver, `/sys/class/drm/card0` |
| **B** | No GPU — Elixir + `$KERNEL_SRC` only; mark reports "hardware N/A" |

Phase 10 exit does **not** require AMD hardware.

## Optional Packages (Path A)

```bash
sudo apt install -y mesa-utils vulkan-tools
glxinfo -B
vulkaninfo --summary
```

## Required Reading

| Resource | Modules |
|----------|---------|
| `Documentation/gpu/` | 10.1, 10.4 |
| `Documentation/core-api/dma-api.rst` (dma_buf preview) | 10.4 |
| DRM code under `drivers/gpu/drm/` | 10.2 |
| `drivers/gpu/drm/amd/amdgpu/` | 10.2, 10.4 |

## Mesa (read-only, do not build)

| Resource | Modules |
|----------|---------|
| [Mesa documentation](https://docs.mesa3d.org/) | 10.3 |
| [Mesa GitLab](https://gitlab.freedesktop.org/mesa/mesa) — browse `src/amd/` | 10.3 |

Optional shallow clone:

```bash
git clone --depth=1 https://gitlab.freedesktop.org/mesa/mesa.git /tmp/mesa
```

## Module Reading Map

| Module | Focus |
|--------|-------|
| 10.1 | `Documentation/gpu/`, worksheet 10.1, `GRAPHICS_STACK.md` |
| 10.2 | Elixir amdgpu tree, MAINTAINERS, `DRM_AMDGPU_WALK.md` |
| 10.3 | Mesa docs, worksheet 10.3, `MESA_GPU_PATH.md` |
| 10.4 | GEM/TTM docs, worksheet 10.4, `GEM_TTM_ANALYSIS.md`, Project 52 Part A |

## Useful Commands (Path A)

```bash
ls /dev/dri/
ls /sys/class/drm/
lspci -nn | grep -i vga
lspci -nn | grep -i amd
# optional trace:
# strace -e openat,ioctl glxinfo 2>&1 | head -40
```

## Gate to Phase 11

Complete [Phase 10 exit gate](../phase-10-amd-driver-graphics/README.md#phase-exit-gate):

- All four module reports submitted
- Project 52 Part A (`AMDGPU_TRACE.md`) complete
- Oral checklist done

Phase 11 completes **Project 52 Part B** — upstream documentation or code contribution informed by your trace. Begin with [Module 11.1](../phase-11-open-source-contributions/module-11-01-patch-workflow-code-reviews/README.md).

Do not submit amdgpu production patches before Phase 11 workflow review.
