# Phase 10 Labs

Worksheets and checklists for graphics stack analysis. **No kernel module starters** — this phase is read/analyze only.

## Setup

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-10.sh
```

Optional:

```bash
sudo apt install -y mesa-utils vulkan-tools
./labs/phase-10/scripts/setup-graphics-tools.sh
```

## Hardware Paths

| Path | When to use |
|------|-------------|
| **A** | AMD GPU host with `/sys/class/drm/card0` and `amdgpu` |
| **B** | No AMD hardware — Elixir Bootlin + `$KERNEL_SRC` only; mark "hardware N/A" in reports |

## Worksheets

| Worksheet | Module |
|-----------|--------|
| [10.1-graphics-stack-tour.md](worksheets/10.1-graphics-stack-tour.md) | 10.1 |
| [10.2-drm-amdgpu-tree.md](worksheets/10.2-drm-amdgpu-tree.md) | 10.2 |
| [10.3-mesa-scheduling.md](worksheets/10.3-mesa-scheduling.md) | 10.3 |
| [10.4-gem-ttm-tour.md](worksheets/10.4-gem-ttm-tour.md) | 10.4 |

## Checklists

[graphics-trace-checklist.md](checklists/graphics-trace-checklist.md) — use before submitting Project 52 Part A.
