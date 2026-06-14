# VM Safety Checklist — Phase 8

Complete **before** booting your first custom-built kernel.

## Host protection

- [ ] I will **not** run `make install` on my host without recovery media and a planned boot entry
- [ ] My host default boot entry is unchanged; I know how to boot the stock kernel
- [ ] I have ≥25 GB free disk for kernel tree and build
- [ ] I have backed up important work unrelated to this lab

## VM strategy

- [ ] I will boot `bzImage` inside **QEMU/KVM** or a dedicated test VM — not as host default
- [ ] I have a root filesystem for the VM (distro cloud image, existing VM disk, or `-initrd` plan documented)
- [ ] I know how to exit QEMU (`Ctrl-a x` or documented shortcut)
- [ ] I recorded the exact QEMU/kernel cmdline in my build log

## Config safety

- [ ] I started from `defconfig` + curriculum fragment, not random full enable
- [ ] I set `CONFIG_LOCALVERSION` so `uname -r` distinguishes my build
- [ ] I understand merged options from [learn-c-base.config](../configs/learn-c-base.config)

## If boot fails

- [ ] I will capture serial/QEMU log before changing many config options
- [ ] I will revert `.config` with `make olddefconfig` or git checkout — not panic-edit host bootloader
- [ ] I know where `bzImage` and `vmlinux` were produced

## Sign-off

Name: _______________  
Date: _______________  
Kernel tag built: _______________
