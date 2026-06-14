# Phase 9 Resources

Canonical reading list for Phase 9 — Kernel Modules and Drivers.

## Pinned Kernel Version

Use the **same tag** as Phase 8 ([resources/phase-08.md](phase-08.md)):

| Item | Value |
|------|-------|
| Recommended tag | `v6.12` |
| Tree | `export KERNEL_SRC="$HOME/src/linux"` |

Module `vermagic` must match the VM kernel built from this tree.

## Enable Modules (Module 9.1)

Merge before rebuilding VM kernel:

```bash
cd "$KERNEL_SRC"
./scripts/kconfig/merge_config.sh .config /path/to/learn-c/labs/phase-09/configs/learn-c-modules.config
make olddefconfig
make -j"$(nproc)" bzImage modules
```

Reboot VM, then verify:

```bash
grep CONFIG_MODULES /boot/config-$(uname -r)   # or your saved .config
ls /proc/modules
```

## Out-of-Tree Module Build

```bash
export KERNEL_SRC="$HOME/src/linux"
cd labs/phase-09/hello-lkm   # or your project dir
make
sudo insmod hello_lkm.ko     # in VM only
dmesg | tail
sudo rmmod hello_lkm
```

Standard Makefile:

```makefile
obj-m += hello_lkm.o
KDIR ?= $(KERNEL_SRC)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
```

## Required Reading

| Resource | Modules |
|----------|---------|
| `Documentation/kbuild/modules.rst` | 9.1 |
| `Documentation/core-api/kernel-api.rst` | 9.2 |
| `Documentation/driver-api/` | 9.2–9.4 |
| `Documentation/filesystems/sysfs.rst` | 9.3 |
| `Documentation/PCI/` | 9.4 |
| `Documentation/core-api/workqueue.rst` | 9.5 |

## Books

| Resource | Notes |
|----------|-------|
| *Linux Kernel Development* (Love) Ch. 8–9 | LKM and driver model |
| Phase 8 [resources/phase-08.md](phase-08.md) | VM boot baseline |

## Module Reading Map

| Module | Focus |
|--------|-------|
| 9.1 | modules.rst, hello-lkm, worksheet 9.1, Project 47 |
| 9.2 | char dev docs, chardev-buffer, user-tools, Project 48 |
| 9.3 | sysfs.rst, sysfs-stats, worksheet 9.3, Project 49 |
| 9.4 | PCI docs, pci-skeleton, worksheet 9.4, Project 50 |
| 9.5 | workqueue.rst, lkm checklist, Project 51 capstone |

## Troubleshooting

| Error | Fix |
|-------|-----|
| `Invalid module format` | Rebuild module against same kernel tree as VM |
| `Unknown symbol` | Module needs export; or build against correct tree |
| `Device or resource busy` on rmmod | Close programs using `/dev` node; stop workqueues |
| Oops on insmod | Read `dmesg`; fix NULL deref; reboot VM if needed |

## Gate to Phase 10

Phase 10 explores DRM and AMDGPU. Complete [Phase 9 exit gate](../phase-09-kernel-modules-drivers/README.md#phase-exit-gate):

- Char device + sysfs module working in VM
- PCI driver analysis + skeleton loaded
- Capstone with deferred work and mutex
- Projects 47–51 complete

Do not start AMDGPU code reading until Phase 10.

Next: [resources/phase-10.md](phase-10.md) — graphics stack and AMDGPU analysis.
