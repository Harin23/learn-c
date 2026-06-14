# Module 6.5 — Device Drivers, Interrupts, and Caches

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain interrupt-driven I/O vs polling
- Describe CPU cache levels and locality (temporal, spatial)
- Measure cache effects with structured memory access patterns
- Map the Linux driver model: char/block drivers, major/minor numbers (preview Part 9)
- Read `/proc/interrupts` and `/sys/class` at a surface level
- Complete Part 6 with integrated hardware–software mental model

## Prerequisites

- Completed [Module 6.4](../module-06-04-filesystems/README.md) exit criteria

## Concepts to Study

1. **Interrupts** — hardware signals CPU; ISR runs; bottom halves preview
2. **Device registers** — MMIO vs port I/O (x86 legacy)
3. **Character vs block devices** — `/dev/tty`, `/dev/sda`
4. **Driver stack** — user → syscall → VFS → driver → hardware
5. **Cache hierarchy** — L1/L2/L3; cache lines (typically 64 bytes)
6. **Locality** — row-major vs column-major matrix access
7. **False sharing preview** — two threads, same cache line
8. **`/proc/interrupts`** — IRQ counts per CPU

## Hands-On Labs

### Lab 1: Cache-Friendly vs Unfriendly

Matrix sum row-major vs column-major; time with `clock_gettime`.

Starter: [labs/part-06/cache_matrix_starter.c](../../labs/part-06/cache_matrix_starter.c)

### Lab 2: Read `/proc/interrupts`

Print lines for timer and keyboard IRQs; run workload; re-read and diff.

### Lab 3: List `/sys/class`

Explore `block/`, `net/`, `drm/` — one paragraph each on purpose.

### Lab 4: perf stat (optional)

```bash
perf stat -e cache-references,cache-misses ./cache_matrix row
perf stat -e cache-references,cache-misses ./cache_matrix col
```

Document counter differences in analysis.

## Mini-Project (Part 6 Capstone)

**Cache and Interrupt Analysis** — [projects/part-06/38-cache-interrupt-analysis.md](../../projects/part-06/38-cache-interrupt-analysis.md)

## Part 6 Oral Checklist (Self-Assessment)

Answer without notes:

1. What is virtual memory for?
2. What happens on a context switch?
3. What is an inode?
4. Why does column-major matrix traversal often lose to row-major?
5. What is an interrupt?
6. How does Part 5 `read()` relate to the page cache?

## Exit Criteria

Before advancing to Part 8 (after Part 7), confirm:

- [ ] Cache benchmark shows measurable row vs column difference
- [ ] `/proc/interrupts` observation documented
- [ ] Project 38 analysis ties caches + interrupts + driver model together
- [ ] All Projects 34–38 complete
- [ ] Part 6 oral checklist completed confidently
- [ ] [Part 6 exit gate](../README.md#part-exit-gate) fully satisfied

## Next Part

[Part 7 — Reading Large Codebases](../../part-07-reading-large-codebases/) (coming soon) — can run in parallel if not yet complete.

[Part 8 — Linux Kernel Fundamentals](../../part-08-linux-kernel-fundamentals/) requires Part 6 + Part 7.
