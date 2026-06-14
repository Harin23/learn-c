# Module 6.2 — Memory Hierarchy and Virtual Memory

**Estimated time:** 14–17 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe memory hierarchy: registers → cache → RAM → disk
- Explain virtual address spaces and why processes have isolated memory
- Read and interpret `/proc/[pid]/maps`
- Understand pages, page tables, and TLB at a conceptual level
- Use `mmap`, `sysconf(_SC_PAGESIZE)`, and `mincore` in experiments

## Prerequisites

- Completed [Module 6.1](../module-06-01-cpu-architecture/README.md) exit criteria

## Concepts to Study

1. **Physical vs virtual address** — MMU translates; each process sees own space
2. **Pages** — typical 4 KiB; huge pages mention (2 MiB)
3. **Page table** — multi-level on x86-64; kernel manages
4. **TLB** — caches translations; miss cost
5. **Demand paging** — pages mapped on first touch; page faults
6. **Copy-on-write** — `fork` optimization revisited
7. **`/proc/pid/maps`** — regions: text, data, heap, stack, mmap, vdso
8. **Swapping** — when RAM pressure; `/proc/meminfo` SwapFree

## Hands-On Labs

### Lab 1: Print Page Size

```c
long ps = sysconf(_SC_PAGESIZE);
```

Starter: [labs/part-06/pagesize_starter.c](../../labs/part-06/pagesize_starter.c)

### Lab 2: Parse `/proc/self/maps`

Print each region: address range, permissions, offset, pathname.

Starter: [labs/part-06/maps_parser_starter.c](../../labs/part-06/maps_parser_starter.c)

### Lab 3: mmap Anonymous Region

Allocate 1 MiB with `mmap`; touch every page; observe RSS in `/proc/self/status` VmRSS.

Starter: [labs/part-06/mmap_touch_starter.c](../../labs/part-06/mmap_touch_starter.c)

### Lab 4: strace mmap/munmap

Trace `mmap`/`munmap`/`brk` during malloc-heavy program (Part 2 darray).

## Mini-Project

**Virtual Memory Map Explorer** — [projects/part-06/35-vm-map-explorer.md](../../projects/part-06/35-vm-map-explorer.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| CS:APP Ch. 9 | Virtual memory |
| TLPI Ch. 20 | Memory mappings |
| `man 2 mmap`, `man 5 proc` | References |

## Exit Criteria

Before advancing to Module 6.3, confirm:

- [ ] maps parser correctly labels heap/stack/libc
- [ ] Can explain why two processes have different address spaces
- [ ] Project 35 report includes annotated `/proc/maps` sample
- [ ] You can define page fault in one sentence

## Next Module

[Module 6.3 — Scheduling and Context Switching](../module-06-03-scheduling/README.md)
