# Module 8.2 — Kernel Build System

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Navigate Kconfig/Kbuild: `Kconfig`, `.config`, Makefiles
- Run `make defconfig`, `menuconfig`, `olddefconfig`, and parallel builds
- Identify build artifacts: `bzImage`, `vmlinux`, `System.map`
- Apply a curriculum config fragment and document config changes
- Boot a custom-built kernel in a VM without altering the host default boot

## Prerequisites

- Completed [Module 8.1](../module-08-01-kernel-architecture-overview/README.md) exit criteria
- Run [labs/phase-08/scripts/setup-kernel-build.sh](../../labs/phase-08/scripts/setup-kernel-build.sh)
- Read [vm-safety-checklist.md](../../labs/phase-08/checklists/vm-safety-checklist.md) before first boot

## Concepts to Study

1. **Kconfig** — `CONFIG_*` symbols; dependencies; `menuconfig` UI
2. **Kbuild** — recursive Makefiles; `obj-y`, `obj-m` (modules deferred to Phase 9)
3. **`make defconfig`** — start from arch default; `scripts/config` helpers
4. **`LOCALVERSION`** — distinguish your build in `uname -r`
5. **Build artifacts** — where `bzImage` and `vmlinux` land on x86_64
6. **Parallel builds** — `-j$(nproc)`; `ccache` optional speedup
7. **VM boot** — QEMU/KVM with `-kernel` and host rootfs or dedicated VM disk
8. **Never on host (yet)** — avoid `make install` on your learning laptop without recovery media

## Hands-On Labs

### Lab 1: Kernel Source Checkout

Reuse Phase 7 clone or clone pinned tag from [resources/phase-08.md](../../resources/phase-08.md):

```bash
export KERNEL_SRC="$HOME/src/linux"
git clone --depth=1 --branch v6.12 https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git "$KERNEL_SRC"
cd "$KERNEL_SRC"
```

Adjust tag to match resources file.

### Lab 2: Kbuild Tour

Worksheet: [labs/phase-08/worksheets/8.2-kbuild-tour.md](../../labs/phase-08/worksheets/8.2-kbuild-tour.md)

Trace one `CONFIG_FTRACE` (or similar) from Kconfig → `.config` → Makefile.

### Lab 3: Build with Curriculum Config Fragment

```bash
cd "$KERNEL_SRC"
make defconfig
./scripts/kconfig/merge_config.sh .config /path/to/learn-c/labs/phase-08/configs/learn-c-base.config
make olddefconfig
make -j"$(nproc)" bzImage
```

Document wall-clock build time.

### Lab 4: Optional ccache

Install `ccache`, set `export CC="ccache gcc"`, rebuild after `make clean` and compare times.

## Mini-Project

**Custom Kernel Build and VM Boot** — [projects/phase-08/43-custom-kernel-build-boot.md](../../projects/phase-08/43-custom-kernel-build-boot.md)

Template script: [labs/phase-08/scripts/qemu-boot-test.sh.template](../../labs/phase-08/scripts/qemu-boot-test.sh.template)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `Documentation/kbuild/` | Official build docs |
| `make help` in kernel tree | Common targets |
| [resources/phase-08.md](../../resources/phase-08.md) | VM setup notes |

## Exit Criteria

Before advancing to Module 8.3, confirm:

- [ ] Worksheet 8.2 completed
- [ ] Clean `bzImage` build with documented `.config` changes
- [ ] VM boots custom kernel; `uname -a` captured in Project 43
- [ ] Host still boots default kernel unchanged
- [ ] VM safety checklist signed off

## Next Module

[Module 8.3 — Kernel Subsystems and APIs](../module-08-03-kernel-subsystems-and-apis/README.md)
