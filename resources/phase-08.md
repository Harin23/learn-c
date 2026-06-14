# Phase 8 Resources

Canonical reading list for Phase 8 — Linux Kernel Fundamentals.

## Pinned Kernel Version

Use a **stable** tag so paths and symbols match course materials. At curriculum publication:

| Item | Value |
|------|-------|
| Recommended tag | `v6.12` (stable branch) |
| Clone | `git clone --depth=1 --branch v6.12 https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git` |
| Shallow alternative | [Elixir Bootlin](https://elixir.bootlin.com/linux/v6.12/source) |

Document your exact tag in every project report. Function names shift between versions.

```bash
export KERNEL_SRC="$HOME/src/linux"
cd "$KERNEL_SRC"
git checkout v6.12
```

## Required Reading

| Resource | Modules |
|----------|---------|
| `Documentation/admin-guide/README.rst` | 8.1 |
| `Documentation/kbuild/` (overview) | 8.2 |
| `Documentation/process/coding-style.rst` | 8.3 |
| `Documentation/process/submitting-patches.rst` | 8.3, 8.5 |
| `Documentation/trace/ftrace.rst` | 8.4 |
| `Documentation/locking/` (intro chapters) | 8.5 |

## Books and Articles

| Resource | Notes |
|----------|-------|
| *Linux Kernel Development* (Robert Love) Ch. 2–7 | Architecture, mm, sched, locking |
| [LWN.net Kernel Index](https://lwn.net/Kernel/Index/) | Deep dives when stuck |
| Phase 7 [resources/phase-07.md](phase-07.md) | Syscall trace baseline |

## Module Reading Map

| Module | Focus |
|--------|-------|
| 8.1 | Love Ch. 2, boot log worksheet, Project 40 notes |
| 8.2 | `Documentation/kbuild/`, learn-c-base.config, VM safety checklist |
| 8.3 | coding-style.rst, checkpatch.pl, Project 44 |
| 8.4 | Love Ch. 4–6, ftrace.rst, Phase 6 Projects 35–36 |
| 8.5 | Love Ch. 7, locking docs, Project 46 capstone |

## VM Setup (QEMU/KVM)

Ubuntu host with KVM:

```bash
sudo apt install -y qemu-system-x86 cpu-checker
kvm-ok   # optional: verify virtualization
```

Create a test VM disk (example — adjust size/path):

```bash
qemu-img create -f qcow2 ~/vm/ubuntu-test.qcow2 20G
# Install distro into disk via virt-manager or debian/ubuntu netinst ISO once
```

Boot template: [labs/phase-08/scripts/qemu-boot-test.sh.template](../labs/phase-08/scripts/qemu-boot-test.sh.template)

**Never** replace host default boot until you have recovery experience.

## Build Tips

```bash
# Parallel build
make -j"$(nproc)" bzImage

# Optional ccache
export CC="ccache gcc"

# Merge curriculum config after defconfig
./scripts/kconfig/merge_config.sh .config /path/to/learn-c/labs/phase-08/configs/learn-c-base.config
make olddefconfig
```

Disk: ~25 GB for tree + `O=build` output if using separate build dir.

## Gate to Phase 9

Phase 9 introduces **loadable kernel modules** and character devices. Complete [Phase 8 exit gate](../phase-08-linux-kernel-fundamentals/README.md#phase-exit-gate) first:

- Custom kernel built and VM-boot tested
- In-tree patch with Signed-off-by and checkpatch review
- ftrace observation report complete
- Locking fundamentals understood

Do not load out-of-tree modules until Phase 9 Module 9.1.

Next: [resources/phase-09.md](phase-09.md) — loadable modules and driver projects.
