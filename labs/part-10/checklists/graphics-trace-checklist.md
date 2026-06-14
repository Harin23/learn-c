# Graphics Trace Checklist — Part 10

Use before submitting `AMDGPU_TRACE.md` (Project 52 Part A). Extends Part 7 trace habits.

## Environment

- [ ] Kernel version tag documented
- [ ] Path A or Path B stated; hardware N/A explicit if Path B
- [ ] Browse tool noted (clone vs Elixir URL)

## Trace quality

- [ ] ≥10 steps with kernel file paths verified in source
- [ ] Function/symbol names match documented kernel tag
- [ ] Userspace steps labeled separately from kernel steps (if included)
- [ ] No copied generic diagrams without matching your trace

## Context

- [ ] Subsystem diagram includes DRM core and amdgpu
- [ ] MAINTAINERS subsection pasted for traced area
- [ ] One `Documentation/gpu/` or DRM doc cited with summary

## Cross-part links

- [ ] References Part 7 trace format (table + diagram)
- [ ] GEM/TTM mentioned if trace touches memory path
- [ ] Part 11 preview section names realistic small contribution type

## Reviewer mindset

- [ ] Another student could reproduce browse steps from your doc
- [ ] Version-specific renames noted where uncertain
- [ ] No claim of live hardware tests unless Path A evidence included

## Sign-off

Trace path chosen: _______________  
Kernel tag: _______________  
Checklist date: _______________
