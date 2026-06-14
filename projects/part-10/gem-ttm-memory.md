# Report: GEM and TTM Memory Analysis

**Module:** 10.4 — Memory Management in Graphics Drivers  
**Estimated time:** 10–12 hours

## Description

Analyze how AMDGPU uses GEM and TTM for GPU memory management. Read kernel source only — no coding.

## Prerequisites

- Part 6 virtual memory review
- Worksheet [10.4-gem-ttm-tour.md](../../labs/part-10/worksheets/10.4-gem-ttm-tour.md)

## Deliverable: `GEM_TTM_ANALYSIS.md`

### 1. Definitions

One paragraph each: GEM, TTM, buffer object, GEM handle.

### 2. VRAM vs GTT

Table comparing VRAM and GTT domains (purpose, typical use, sysfs hint if Path A).

### 3. Source map

| Symbol / file | Role in memory management |
|---------------|---------------------------|

Minimum **6 entries** in amdgpu or TTM code.

### 4. Lifecycle narrative

Numbered steps: userspace requests buffer → kernel creates BO → maps to GPU/CPU (high level, 6–10 steps).

### 5. dma_buf preview

One paragraph: why dma_buf exists; one amdgpu or DRM reference file.

### 6. Part 6 tie-in

One paragraph linking process virtual memory (`/proc/maps`) to GPU memory domains (conceptual).

## Rubric

| Criterion | Points |
|-----------|--------|
| Definitions and VRAM/GTT table | 25 |
| Source map (≥6 entries) | 30 |
| Lifecycle narrative | 25 |
| dma_buf + Part 6 tie-in | 10 |
| Worksheet 10.4 completed | 10 |
| **Total** | **100** |

## Optional (Path A)

Paste `mem_info_vram_total` or related sysfs if available.
