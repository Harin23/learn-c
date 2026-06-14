# Project 47: Hello LKM with Module Parameter

**Module:** 9.1 — Loadable Kernel Modules  
**Estimated time:** 8–12 hours

## Description

Extend the hello LKM lab into a complete module with a tunable integer parameter, proper metadata, and documented VM load/unload procedure.

## Prerequisites

- VM kernel with `CONFIG_MODULES=y`
- [labs/phase-09/hello-lkm/](../../labs/phase-09/hello-lkm/) completed or used as base
- Worksheet [9.1-lkm-build-load.md](../../labs/phase-09/worksheets/9.1-lkm-build-load.md)

## Requirements

1. Module name: `learn_hello.ko` (source file `learn_hello.c`)
2. `MODULE_LICENSE("GPL")`, `MODULE_AUTHOR`, `MODULE_DESCRIPTION`
3. Integer module parameter `greet_count` (default 1) with `MODULE_PARM_DESC`
4. `module_init` prints greeting `greet_count` times to kernel log
5. `module_exit` prints farewell message
6. Builds with standard out-of-tree Makefile against `$KERNEL_SRC`

## Deliverables

1. **Source + Makefile** (in your project directory or fork of hello-lkm)
2. **`MODULE_README.md`** containing:
   - Build commands
   - Copy-to-VM steps (scp, shared folder, etc.)
   - Load: `sudo insmod learn_hello.ko greet_count=3`
   - `modinfo learn_hello.ko` output (paste)
   - `dmesg` snippet showing three greetings
   - Unload: `sudo rmmod learn_hello`
3. VM kernel version (`uname -r`) documented

## Rubric

| Criterion | Points |
|-----------|--------|
| Module builds without errors | 25 |
| Loads/unloads cleanly in VM | 25 |
| Module parameter works (test greet_count=3) | 25 |
| MODULE_* metadata present | 10 |
| MODULE_README complete | 15 |
| **Total** | **100** |

## Troubleshooting (document if hit)

- `Invalid module format` / vermagic — rebuild module or kernel to match
- `Operation not permitted` — use `sudo insmod` in VM

## Safety

[module-vm-safety-checklist.md](../../labs/phase-09/checklists/module-vm-safety-checklist.md) — VM only.
