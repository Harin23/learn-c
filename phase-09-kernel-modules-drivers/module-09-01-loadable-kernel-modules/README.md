# Module 9.1 — Loadable Kernel Modules

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain module lifecycle with `module_init` and `module_exit`
- Build out-of-tree modules with the kernel Kbuild `M=` Makefile pattern
- Load and unload modules with `insmod`, `rmmod`, and inspect with `modinfo`
- Use `MODULE_LICENSE`, `MODULE_AUTHOR`, and module parameters
- Verify module activity in `dmesg` inside your Phase 8 VM

## Prerequisites

- [Phase 8 exit gate](../../phase-08-linux-kernel-fundamentals/README.md#phase-exit-gate)
- `$KERNEL_SRC` set to the same tree used to build your VM kernel
- Read [module-vm-safety-checklist.md](../../labs/phase-09/checklists/module-vm-safety-checklist.md)

## Concepts to Study

1. **Loadable modules** — separate `.ko` objects linked at runtime
2. **`module_init` / `module_exit`** — entry and cleanup hooks
3. **Out-of-tree build** — `make -C $KERNEL_SRC M=$PWD modules`
4. **`vermagic`** — module must match running kernel version/config
5. **`insmod` / `rmmod` / `modinfo`** — user-space module tools
6. **Module parameters** — `module_param`, `MODULE_PARM_DESC`
7. **GPL licensing** — `MODULE_LICENSE("GPL")` requirement for many APIs
8. **Module loader path** — read-only trace in `$KERNEL_SRC` (worksheet)

## Hands-On Labs

### Lab 1: Enable Modules in VM Kernel

Merge [labs/phase-09/configs/learn-c-modules.config](../../labs/phase-09/configs/learn-c-modules.config) into your Phase 8 `.config`:

```bash
cd "$KERNEL_SRC"
./scripts/kconfig/merge_config.sh .config /path/to/learn-c/labs/phase-09/configs/learn-c-modules.config
make olddefconfig
make -j"$(nproc)" bzImage modules
```

Reboot VM; confirm `/proc/modules` exists and `CONFIG_MODULES=y` in `/boot/config-$(uname -r)` or your built config.

### Lab 2: Orient to Kernel Samples

Browse `$KERNEL_SRC/samples/` — pick one small sample Makefile and read how it builds (no need to load in-tree samples yet).

### Lab 3: Build and Load hello-lkm

Complete [labs/phase-09/hello-lkm/](../../labs/phase-09/hello-lkm/) starter; copy `.ko` to VM; `sudo insmod hello_lkm.ko`; check `dmesg`; `sudo rmmod hello_lkm`.

### Lab 4: insmod Path Worksheet

Worksheet: [labs/phase-09/worksheets/9.1-lkm-build-load.md](../../labs/phase-09/worksheets/9.1-lkm-build-load.md)

## Mini-Project

**Hello LKM with Module Parameter** — [projects/phase-09/47-hello-lkm-parameter.md](../../projects/phase-09/47-hello-lkm-parameter.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [resources/phase-09.md](../../resources/phase-09.md) | Build commands |
| `Documentation/kbuild/modules.rst` | Out-of-tree modules |
| *Linux Kernel Development* (Love) Ch. 8 intro | LKM overview |

## Exit Criteria

Before advancing to Module 9.2, confirm:

- [ ] VM kernel rebuilt with `CONFIG_MODULES=y`
- [ ] Worksheet 9.1 completed
- [ ] hello-lkm loads and unloads without errors
- [ ] Project 47 module parameter works via `modinfo`/`insmod`
- [ ] Module work performed only in VM

## Next Module

[Module 9.2 — Character Devices](../module-09-02-character-devices/README.md)
