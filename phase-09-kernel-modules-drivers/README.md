# Phase 9 — Kernel Modules and Drivers

Build out-of-tree loadable kernel modules, character devices, sysfs interfaces, and PCI driver skeletons in your Phase 8 VM. This phase bridges in-tree kernel work (Phase 8) and graphics stack exploration (Phase 10).

**Estimated time:** 75–90 hours (5 modules × 15–18 hours)

## Modules

Complete these in order. Each module builds on the previous one.

| Module | Title | Hours |
|--------|-------|-------|
| [9.1](module-09-01-loadable-kernel-modules/README.md) | Loadable Kernel Modules | 15–18 |
| [9.2](module-09-02-character-devices/README.md) | Character Devices | 15–18 |
| [9.3](module-09-03-sysfs-and-procfs/README.md) | Sysfs and Procfs | 15–18 |
| [9.4](module-09-04-driver-architecture-pci/README.md) | Driver Architecture and PCI Devices | 15–18 |
| [9.5](module-09-05-hardware-interfaces/README.md) | Hardware Interfaces | 15–18 |

## Prerequisites

**Required:** [Phase 8 exit gate](../phase-08-linux-kernel-fundamentals/README.md#phase-exit-gate)

Reuse your Phase 8 setup:

```bash
export KERNEL_SRC="$HOME/src/linux"
```

Before Module 9.1, rebuild your VM kernel with module support — merge [labs/phase-09/configs/learn-c-modules.config](../labs/phase-09/configs/learn-c-modules.config) into your Phase 8 `.config`, then rebuild and reboot the VM.

Run `./scripts/verify-phase-09.sh` from the repository root.

**Safety:** Load modules (`insmod`) only in your Phase 8 VM, not on your host production kernel. See [labs/phase-09/checklists/module-vm-safety-checklist.md](../labs/phase-09/checklists/module-vm-safety-checklist.md).

## Scope

| In this phase | Deferred to Phase 10 |
|---------------|----------------------|
| Out-of-tree LKM build, `insmod`/`rmmod` | DRM, Mesa, AMDGPU |
| Char devices, `file_operations` | GPU scheduling, GEM/TTM |
| Sysfs/procfs module attributes | Graphics upstream contributions |
| PCI driver model, probe/remove skeleton | Real AMD GPU bring-up |
| Timer/workqueue deferred work (VM-safe) | Production driver patches |

## Phase Exit Gate

Do not start Phase 10 until you can independently:

- Build out-of-tree modules against your Phase 8 VM kernel tree and load/unload them safely in the VM
- Implement a char device with correct `copy_to_user`/`copy_from_user` usage
- Expose module state via sysfs and clean up on unload
- Explain PCI driver probe/remove and trace a bound device to in-tree driver source
- Use mutexes appropriately in module code; explain why IRQ handlers stay minimal
- Complete all Phase 9 projects (47–51) with module READMEs and VM test logs

## Resources

See [resources/phase-09.md](../resources/phase-09.md) for the canonical reading list.

## Projects in This Phase

| # | Project | Module | Spec |
|---|---------|--------|------|
| 47 | Hello LKM with module parameter | 9.1 | [47-hello-lkm-parameter.md](../projects/phase-09/47-hello-lkm-parameter.md) |
| 48 | Circular buffer char device | 9.2 | [48-chardev-buffer.md](../projects/phase-09/48-chardev-buffer.md) |
| 49 | Sysfs monitoring module | 9.3 | [49-sysfs-monitoring-module.md](../projects/phase-09/49-sysfs-monitoring-module.md) |
| 50 | PCI driver architecture lab | 9.4 | [50-pci-driver-architecture.md](../projects/phase-09/50-pci-driver-architecture.md) |
| 51 | Phase 9 driver capstone | 9.5 | [51-driver-capstone.md](../projects/phase-09/51-driver-capstone.md) |
