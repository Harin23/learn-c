# Project 38: Cache and Interrupt Analysis (Phase 6 Capstone)

**Module:** 6.5 — Device Drivers, Interrupts, and Caches  
**Estimated time:** 7–9 hours

## Description

Combine empirical cache measurement with `/proc/interrupts` observation and a written synthesis tying hardware behavior to OS concepts from Phase 6.

## Part A — Cache Benchmark Program

Implement matrix traversal benchmark from lab:

```bash
cachebench row 1024
cachebench col 1024
```

Print elapsed seconds and optional checksum (prevent optimizer removing work).

Requirements:

- Allocate `N×N` `double` matrix; initialize
- Row-major sum vs column-major sum
- Use `clock_gettime(CLOCK_MONOTONIC)`

Starter: [labs/phase-06/cache_matrix_starter.c](../../labs/phase-06/cache_matrix_starter.c)

## Part B — Interrupt Observation

Script or documented manual procedure:

1. Capture `/proc/interrupts` baseline
2. Generate network/disk/timer activity (e.g. `ping -c 100`, read large file)
3. Capture again; diff IRQ counters

Include table in `ANALYSIS.md`.

## Part C — Synthesis Document (`ANALYSIS.md`)

Required sections:

1. **Caches** — row vs column results; explain with locality and cache lines
2. **Interrupts** — which IRQs increased; what device/driver likely handles them
3. **Driver stack** — one diagram: user program → syscall → block layer → driver → IRQ
4. **Phase 6 integration** — paragraph linking modules 6.1–6.5 to one `read()` path

Optional: `perf stat` comparison attached as appendix.

## Rubric

| Criterion | Points |
|-----------|--------|
| Cache benchmark shows row faster than col (typical) | 25 |
| Interrupt before/after documented | 20 |
| Driver stack diagram | 20 |
| Integration essay | 25 |
| Zero warnings on cachebench | 10 |
| **Total** | **100** |

## Phase 6 Completion

Passing Projects 34–38 (≥80 each average or all ≥70) completes Phase 6.

## Extension (Optional)

Demonstrate false sharing with two threads incrementing adjacent counters.
