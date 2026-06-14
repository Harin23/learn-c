# Part 9 Projects

Out-of-tree kernel module and driver projects — all testing in Part 8 VM.

| # | Project | Module | Spec |
|---|---------|--------|------|
| 47 | Hello LKM with module parameter | 9.1 | [47-hello-lkm-parameter.md](47-hello-lkm-parameter.md) |
| 48 | Circular buffer char device | 9.2 | [48-chardev-buffer.md](48-chardev-buffer.md) |
| 49 | Sysfs monitoring module | 9.3 | [49-sysfs-monitoring-module.md](49-sysfs-monitoring-module.md) |
| 50 | PCI driver architecture lab | 9.4 | [50-pci-driver-architecture.md](50-pci-driver-architecture.md) |
| 51 | Part 9 driver capstone | 9.5 | [51-driver-capstone.md](51-driver-capstone.md) |

See [docs/project-sequence.md](../docs/project-sequence.md) for the full roadmap.

Kernel modules: build against `$KERNEL_SRC` matching your VM kernel. User-space test tools: compile with `-Wall -Wextra -std=c11`.
