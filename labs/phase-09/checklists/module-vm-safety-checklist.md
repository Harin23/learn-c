# Module VM Safety Checklist — Phase 9

Complete before first `insmod` in Phase 9.

## VM and kernel match

- [ ] I load modules only in my Phase 8 test VM — **not** on host production kernel
- [ ] VM kernel was rebuilt with [learn-c-modules.config](../configs/learn-c-modules.config)
- [ ] Module built with same `$KERNEL_SRC` / version as running VM kernel
- [ ] I understand `vermagic` / `Invalid module format` troubleshooting

## Load/unload discipline

- [ ] I run `sudo rmmod` before rebuilding and reloading the same module
- [ ] I check `dmesg` after every insmod and rmmod
- [ ] I have a VM snapshot before experimenting with new module code
- [ ] I will not `insmod` modules that oops — fix, rebuild, reboot VM if needed

## PCI safety

- [ ] PCI skeleton uses non-matching device ID unless instructor approved test device
- [ ] I will not unbind virtio/network/storage drivers on a VM I need for networking

## Device nodes

- [ ] `mknod` permissions are relaxed only in lab VM
- [ ] I remove stale `/dev` nodes after changing major numbers

## Sign-off

Name: _______________  
Date: _______________  
VM `uname -r`: _______________
