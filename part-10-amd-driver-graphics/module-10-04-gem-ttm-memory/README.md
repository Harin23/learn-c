# Module 10.4 — Memory Management in Graphics Drivers

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain GEM handles and TTM buffer objects at a conceptual level
- Distinguish VRAM (GPU-local) from GTT/system memory domains
- Locate GEM/TTM-related code in amdgpu source (read-only)
- Preview `dma_buf` sharing between drivers
- Complete **Project 52 Part A** — AMDGPU trace report

## Prerequisites

- Completed [Module 10.3](../module-10-03-mesa-gpu-scheduling/README.md) exit criteria
- Part 6 virtual memory concepts reviewed

## Concepts to Study

1. **GEM** — Graphics Execution Manager; handle-based GPU memory API in DRM
2. **TTM** — Translation Table Maps; memory manager for GPU buffers
3. **VRAM vs GTT** — local GPU memory vs mapped system RAM
4. **BO** — buffer object lifecycle (create, map, destroy)
5. **`dma_buf`** — buffer sharing between subsystems (preview)
6. **Part 6 tie-in** — page tables vs GPU page tables (high level only)
7. **Sysfs** — optional `mem_info_vram_total` on AMD hardware
8. **Trace planning** — pick Project 52 path (open, GEM create, or CS ioctl)

## Hands-On Labs

### Lab 1: GEM/TTM Source Tour

Worksheet: [labs/part-10/worksheets/10.4-gem-ttm-tour.md](../../labs/part-10/worksheets/10.4-gem-ttm-tour.md)

Locate six symbols/files in `$KERNEL_SRC` (e.g. `amdgpu_gem_*`, `ttm_bo_*`).

### Lab 2: Kernel Documentation

Read intro sections of `Documentation/gpu/` or DRM memory management doc; 5-line summary.

### Lab 3: Optional Hardware Sysfs

```bash
cat /sys/class/drm/card0/device/mem_info_vram_total 2>/dev/null || echo "N/A"
```

### Lab 4: Plan Project 52 Trace

Choose trace path; draft outline table before writing `AMDGPU_TRACE.md`.

Apply [graphics-trace-checklist.md](../../labs/part-10/checklists/graphics-trace-checklist.md).

## Module Report

**GEM/TTM Analysis** — [projects/part-10/gem-ttm-memory.md](../../projects/part-10/gem-ttm-memory.md)

Deliverable: `GEM_TTM_ANALYSIS.md`

## Capstone — Project 52 Part A

**AMDGPU Trace** — [projects/part-10/52-amdgpu-trace-part-a.md](../../projects/part-10/52-amdgpu-trace-part-a.md)

Deliverable: `AMDGPU_TRACE.md` (completes Part A of curriculum Project 52)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/gpu/` | Memory management sections |
| Part 6 [Module 6.2](../../part-06-computer-architecture-os/module-06-02-virtual-memory/README.md) | VM baseline |

## Part 10 Oral Checklist (Self-Assessment)

Answer without notes:

1. Name four layers from app to AMD GPU hardware.
2. Where does amdgpu live in the kernel tree?
3. What does Mesa do that amdgpu does not?
4. VRAM vs GTT — one sentence each.
5. What is a GEM handle?
6. What will Project 52 Part B add in Part 11?

## Exit Criteria

Before advancing to Part 11, confirm:

- [ ] Worksheet 10.4 completed
- [ ] `GEM_TTM_ANALYSIS.md` complete
- [ ] `AMDGPU_TRACE.md` (Project 52 Part A) complete with checklist
- [ ] All module reports 10.1–10.4 submitted
- [ ] Part 10 oral checklist completed confidently
- [ ] [Part 10 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 11 — Open Source Contributions](../../part-11-open-source-contributions/)

Complete Project 52 Part B (upstream contribution).
