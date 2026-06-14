# Module 10.3 — Mesa Overview and GPU Scheduling

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain why Mesa exists and how it relates to kernel DRM/amdgpu
- Describe Gallium and winsys at a high level (no Mesa build required)
- Identify where Mesa's AMD driver talks to the kernel (ioctl/libdrm)
- Compare CPU scheduling (Phase 6) to GPU command submission conceptually
- Browse Mesa `src/amd/` read-only (GitHub or shallow clone)

## Prerequisites

- Completed [Module 10.2](../module-10-02-drm-amdgpu-architecture/README.md) exit criteria

## Concepts to Study

1. **Mesa** — open-source graphics API implementations
2. **Gallium** — Mesa driver framework (pipe drivers)
3. **Winsys** — window system / kernel interface layer
4. **RadeonSI / RADV** — AMD GPU Mesa drivers (names preview)
5. **GPU scheduling** — command submission, rings, fences (conceptual)
6. **Userspace vs kernel** — Mesa packs ioctls; kernel validates and schedules
7. **Phase 6 contrast** — CFS vs GPU hardware queues
8. **No Mesa build** — read docs and source only in this module

## Hands-On Labs

### Lab 1: Mesa Documentation

Read [Mesa documentation](https://docs.mesa3d.org/) architecture/overview sections (~1 hour). Summarize in 10 lines.

### Lab 2: Browse Mesa AMD Source

Shallow clone optional:

```bash
git clone --depth=1 https://gitlab.freedesktop.org/mesa/mesa.git /tmp/mesa
ls /tmp/mesa/src/amd/
```

Or browse on GitLab web UI — document paths only.

### Lab 3: Mesa Scheduling Worksheet

Worksheet: [labs/phase-10/worksheets/10.3-mesa-scheduling.md](../../labs/phase-10/worksheets/10.3-mesa-scheduling.md)

### Lab 4: Written Comparison

Two paragraphs: Phase 6 round-robin/ CFS vs GPU command queue scheduling (qualitative).

## Module Report

**Mesa/GPU Scheduling Path** — [projects/phase-10/mesa-gpu-scheduling.md](../../projects/phase-10/mesa-gpu-scheduling.md)

Deliverable: `MESA_GPU_PATH.md`

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [Mesa wiki](https://gitlab.freedesktop.org/mesa/mesa/-/wikis/home) | Project overview |
| Phase 6 [Module 6.3](../../phase-06-computer-architecture-os/module-06-03-scheduling/README.md) | CPU scheduling baseline |

## Exit Criteria

Before advancing to Module 10.4, confirm:

- [ ] Worksheet 10.3 completed
- [ ] Can explain Mesa's role without conflating it with kernel amdgpu
- [ ] Names one Mesa→kernel boundary (function or ioctl category)
- [ ] `MESA_GPU_PATH.md` complete

## Next Module

[Module 10.4 — Memory Management in Graphics Drivers](../module-10-04-gem-ttm-memory/README.md)
