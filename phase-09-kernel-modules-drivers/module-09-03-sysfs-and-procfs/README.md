# Module 9.3 — Sysfs and Procfs

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Expose module statistics through sysfs attribute files
- Use `DEVICE_ATTR`, `device_create_file`, and cleanup on unload
- Navigate `/sys/class` and `/sys/bus/pci/devices` (Phase 6 revisit)
- Optionally add a simple `/proc` seq_file entry
- Ensure sysfs files disappear cleanly after `rmmod`

## Prerequisites

- Completed [Module 9.2](../module-09-02-character-devices/README.md) exit criteria
- Project 48 char device working in VM

## Concepts to Study

1. **Sysfs** — kernel objects exported as a filesystem
2. **`kobject` / device model** — high-level view only
3. **`DEVICE_ATTR` / `sysfs_attr`** — read/store callbacks
4. **`device_create` + class** — automatic `/dev` and `/sys/class/...`
5. **Procfs** — legacy; `seq_file` for read handlers
6. **`/sys/bus/pci/devices`** — PCI device attributes
7. **Attribute permissions** — read-only vs read-write for tunables
8. **Unload ordering** — remove sysfs before unregistering device

## Hands-On Labs

### Lab 1: Inspect Project 48 in sysfs

If using `device_create`, find your device under `/sys/class/`. Document paths.

### Lab 2: PCI Sysfs Tour

Worksheet: [labs/phase-09/worksheets/9.3-sysfs-tour.md](../../labs/phase-09/worksheets/9.3-sysfs-tour.md)

### Lab 3: Add Stats to Chardev Module

Extend Project 48 (or [sysfs-stats starter](../../labs/phase-09/sysfs-stats/)) with `read_count` and `write_count` sysfs files.

### Lab 4: Optional procfs Entry

Add minimal `/proc/learn_c_stats` using seq_file — remove in `module_exit`.

## Mini-Project

**Sysfs Monitoring Module** — [projects/phase-09/49-sysfs-monitoring-module.md](../../projects/phase-09/49-sysfs-monitoring-module.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/filesystems/sysfs.rst` | Sysfs rules |
| `Documentation/driver-api/driver-model/` | Device model overview |

## Exit Criteria

Before advancing to Module 9.4, confirm:

- [ ] Worksheet 9.3 completed
- [ ] Sysfs files readable with `cat` in VM
- [ ] Attributes removed after `rmmod` (no stale files)
- [ ] Project 49 complete

## Next Module

[Module 9.4 — Driver Architecture and PCI Devices](../module-09-04-driver-architecture-pci/README.md)
