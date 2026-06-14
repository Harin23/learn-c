# Project 50: PCI Driver Architecture Lab

**Module:** 9.4 — Driver Architecture and PCI Devices  
**Estimated time:** 12–16 hours

## Description

Combine a written PCI driver trace with an out-of-tree `pci_driver` skeleton that registers probe/remove handlers. Probe firing on a real device is **bonus** — passing grade requires analysis + loadable module without oops.

## Part A — Analysis: `PCI_DRIVER_ANALYSIS.md`

1. VM environment: `uname -r`, `lspci -nn` output (one page max)
2. Pick **one bound PCI device** (e.g. virtio, IDE, display)
3. Table:

   | Field | Value |
   |-------|-------|
   | PCI slot | |
   | Vendor:Device | |
   | Bound driver name | |
   | sysfs driver path | |
   | In-tree source file | |
   | probe function name | |

4. Two paragraphs: what `probe` does for that device (high level)
5. MAINTAINERS or `Documentation/PCI/` reference if applicable

## Part B — Code: `learn_pci_demo.ko`

Based on [labs/part-09/pci-skeleton/](../../labs/part-09/pci-skeleton/):

1. `pci_driver` with `.name`, `.id_table`, `.probe`, `.remove`
2. `pci_device_id` table with **non-matching** vendor/device (e.g. `0xFFFF, 0xFFFF`) so VM load is safe
3. `probe`/`remove` log with `dev_info`
4. `module_init` registers driver; `module_exit` unregisters
5. Loads in VM without oops; dmesg shows driver registered

## Deliverables

1. `PCI_DRIVER_ANALYSIS.md`
2. `learn_pci_demo.ko` source + Makefile
3. **`MODULE_README.md`**: build, insmod, dmesg, rmmod log

## Rubric

| Criterion | Points |
|-----------|--------|
| Analysis table accurate (spot-check) | 35 |
| pci_driver registers (dmesg proof) | 25 |
| probe/remove implemented (bonus if probe runs) | 15 |
| Safe non-matching ID table documented | 10 |
| Worksheet 9.4 completed | 10 |
| MODULE_README | 5 |
| **Total** | **100** |

## Safety

Do **not** use `PCI_ANY_ID` or match devices bound to critical VM functionality without instructor approval.

## Worksheet

[9.4-pci-driver-trace.md](../../labs/part-09/worksheets/9.4-pci-driver-trace.md)
