# Phase 9 Labs

Out-of-tree kernel module starters and worksheets. Kernel source is **not** vendored — set `KERNEL_SRC` to your Phase 8 tree.

## Setup

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-09.sh
```

Before Module 9.1, merge [configs/learn-c-modules.config](configs/learn-c-modules.config) into your Phase 8 kernel config and rebuild the VM kernel.

## Build Pattern

From any starter directory:

```bash
export KERNEL_SRC="$HOME/src/linux"
make
```

Produces `.ko` in the same directory. Copy to VM and `sudo insmod module.ko`.

## Directory Layout

| Path | Purpose |
|------|---------|
| [configs/learn-c-modules.config](configs/learn-c-modules.config) | CONFIG_MODULES fragment |
| [hello-lkm/](hello-lkm/) | Basic LKM starter |
| [chardev-buffer/](chardev-buffer/) | Circular buffer char device |
| [sysfs-stats/](sysfs-stats/) | Char dev + sysfs stats skeleton |
| [pci-skeleton/](pci-skeleton/) | PCI driver registration skeleton |
| [user-tools/](user-tools/) | User-space test programs |
| [worksheets/](worksheets/) | Module 9.1–9.5 |
| [checklists/](checklists/) | VM safety and LKM review |

## User-Space Test Tools

```bash
gcc -Wall -Wextra -std=c11 -o test_read user-tools/test_read.c
gcc -Wall -Wextra -std=c11 -o test_write user-tools/test_write.c
```

## Safety

Read [checklists/module-vm-safety-checklist.md](checklists/module-vm-safety-checklist.md) before `insmod`.
