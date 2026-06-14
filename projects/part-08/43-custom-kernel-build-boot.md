# Project 43: Custom Kernel Build and VM Boot

**Module:** 8.2 — Kernel Build System  
**Estimated time:** 12–16 hours (includes build wait time)

## Description

Configure, build, and boot a custom Linux kernel in a VM. Document the full workflow without changing your host machine's default boot entry.

## Prerequisites

- [vm-safety-checklist.md](../../labs/part-08/checklists/vm-safety-checklist.md) completed
- [resources/part-08.md](../../resources/part-08.md) pinned kernel tag
- Worksheet [8.2-kbuild-tour.md](../../labs/part-08/worksheets/8.2-kbuild-tour.md)

## Safety

- **Do not** run `make install` on your host learning laptop unless you have recovery media and a separate boot entry plan.
- Boot the custom `bzImage` only inside QEMU/KVM or a dedicated test VM.
- Keep host GRUB/default kernel unchanged.

## Steps

1. Clone or checkout pinned kernel tag into `$KERNEL_SRC`
2. `make defconfig`
3. Merge [learn-c-base.config](../../labs/part-08/configs/learn-c-base.config):

   ```bash
   ./scripts/kconfig/merge_config.sh .config /path/to/learn-c/labs/part-08/configs/learn-c-base.config
   make olddefconfig
   ```

4. Set `CONFIG_LOCALVERSION="-learn-c"` (via `menuconfig` or fragment)
5. `make -j"$(nproc)" bzImage`
6. Boot in VM using [qemu-boot-test.sh.template](../../labs/part-08/scripts/qemu-boot-test.sh.template) (copy and customize)
7. Inside VM: `uname -a`, `cat /proc/version`, save output

## Deliverable: `BUILD_LOG.md`

### 1. Environment

- CPU cores, RAM, disk free
- `gcc --version`, `make --version`
- Kernel tag and `KERNEL_SRC` path

### 2. Configuration

- Commands run (defconfig, merge, olddefconfig)
- `diff` of meaningful `.config` changes vs defconfig (or attach `.config.diff`)
- Why you enabled/disabled at least **three** non-default options

### 3. Build

- Exact build command
- Wall-clock time (first build)
- Output paths: `arch/x86/boot/bzImage`, `vmlinux` size

### 4. VM boot proof

- QEMU command line (or VM manager settings)
- `uname -a` from **inside** VM running your kernel
- Screenshot or pasted terminal proof host still runs original kernel (`uname -r` on host)

### 5. Troubleshooting section

Document at least one problem encountered (config error, missing package, VM boot hang) and fix.

## Rubric

| Criterion | Points |
|-----------|--------|
| Documented config workflow + `.config` diff | 25 |
| Successful `bzImage` build with timing | 20 |
| VM boots custom kernel (`uname -a` proof) | 30 |
| Host default boot unchanged | 10 |
| VM safety checklist referenced | 5 |
| Troubleshooting documented | 10 |
| **Total** | **100** |

## Worksheet

[labs/part-08/worksheets/8.2-kbuild-tour.md](../../labs/part-08/worksheets/8.2-kbuild-tour.md)

## Template

[labs/part-08/scripts/qemu-boot-test.sh.template](../../labs/part-08/scripts/qemu-boot-test.sh.template)
