# LKM Review Checklist — Part 9

Use before submitting Projects 48–51. Extends [Part 8 kernel patch checklist](../../part-08/checklists/kernel-patch-review-checklist.md).

## Build and load

- [ ] Built with `make -C $KERNEL_SRC M=$PWD modules`
- [ ] Loads in VM without vermagic errors
- [ ] Unloads cleanly with `rmmod` (no oops)
- [ ] `dmesg` checked after load, exercise, unload

## Correctness

- [ ] User pointers use `copy_to_user` / `copy_from_user`
- [ ] Return values follow kernel conventions (bytes or negative errno)
- [ ] No blocking in invalid context (if using workqueues, documented)
- [ ] Shared data protected by mutex where needed

## Registration cleanup

- [ ] `module_exit` reverses `module_init` (cdev, region, class, device, sysfs, pci_driver)
- [ ] Timer/workqueue canceled before unregister
- [ ] Sysfs files removed before device_destroy

## Style and metadata

- [ ] `MODULE_LICENSE("GPL")` present
- [ ] `checkpatch.pl` run on `.c` sources; issues fixed or documented
- [ ] No user-space headers in kernel code

## Documentation

- [ ] MODULE_README or CAPSTONE_README with build/load/test steps
- [ ] VM test log pasted
- [ ] Major/minor or sysfs paths documented

## Sign-off

Module name: _______________  
checkpatch warnings remaining: _______________  
VM test pass: yes / no
