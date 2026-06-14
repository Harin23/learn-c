# Module 9.4 — Driver Architecture and PCI Devices

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Describe the Linux driver model: bus, driver, device
- Implement a `struct pci_driver` with `probe` and `remove` callbacks
- Define a `pci_device_id` table and register with `pci_register_driver`
- Use `lspci` and `/sys/bus/pci` to inspect VM devices
- Trace an existing bound PCI driver in `$KERNEL_SRC` — **without unbinding host/VM system devices**

## Prerequisites

- Completed [Module 9.3](../module-09-03-sysfs-and-procfs/README.md) exit criteria

## Concepts to Study

1. **PCI bus** — vendor/device IDs, BARs (conceptual)
2. **`pci_driver`** — driver registration lifecycle
3. **`probe` / `remove`** — bind and unbind device
4. **`pci_device_id` table** — match rules; `{0}` terminator
5. **`lspci -nn`** — user-space PCI listing
6. **`/sys/bus/pci/devices/`** — kernel PCI sysfs view
7. **Driver binding** — why your skeleton may probe zero devices (OK)
8. **Safety** — never force-bind over critical VM devices without isolation

## Hands-On Labs

### Lab 1: lspci and sysfs Tour

In VM: `lspci -nn`; pick one device; list sysfs path and `driver` symlink if bound.

### Lab 2: PCI Driver Trace Worksheet

Worksheet: [labs/part-09/worksheets/9.4-pci-driver-trace.md](../../labs/part-09/worksheets/9.4-pci-driver-trace.md)

Trace one bound device to in-tree driver source file.

### Lab 3: pci-skeleton Module

Build and load [labs/part-09/pci-skeleton/](../../labs/part-09/pci-skeleton/) in VM. Confirm registration in `dmesg`; zero probes is acceptable.

### Lab 4: Document Match Table Strategy

Write why your module uses a non-matching ID table (or which test device would match in an isolated lab).

## Mini-Project

**PCI Driver Architecture Lab** — [projects/part-09/50-pci-driver-architecture.md](../../projects/part-09/50-pci-driver-architecture.md)

Deliverables: `PCI_DRIVER_ANALYSIS.md` + `learn_pci_demo.ko`.

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/PCI/` | PCI driver guide |
| *Linux Kernel Development* (Love) Ch. 8 | Device model |

## Exit Criteria

Before advancing to Module 9.5, confirm:

- [ ] Worksheet 9.4 completed with in-tree driver trace
- [ ] pci-skeleton loads without oops
- [ ] Can explain probe/remove even if probe count is zero
- [ ] Project 50 deliverables complete

## Next Module

[Module 9.5 — Hardware Interfaces](../module-09-05-hardware-interfaces/README.md)
