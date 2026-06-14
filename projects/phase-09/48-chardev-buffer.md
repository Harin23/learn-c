# Project 48: Circular Buffer Char Device

**Module:** 9.2 — Character Devices  
**Estimated time:** 12–16 hours

## Description

Implement a loadable kernel module exposing a fixed-size circular buffer through a character device. User-space tools write data into the buffer and read it back in FIFO order.

## Prerequisites

- Module 9.1 complete
- Starter: [labs/phase-09/chardev-buffer/](../../labs/phase-09/chardev-buffer/)
- Test tools: [test_read.c](../../labs/phase-09/user-tools/test_read.c), [test_write.c](../../labs/phase-09/user-tools/test_write.c)

## Requirements

1. Fixed buffer size **4096** bytes (circular/FIFO)
2. Dynamic major via `alloc_chrdev_region` or documented static major + `mknod`
3. `file_operations`: `open`, `read`, `write`, `release` (optional `llseek`)
4. All user data via `copy_to_user` / `copy_from_user`
5. Return `-EAGAIN` or `0` on read from empty buffer (document behavior in README)
6. Module unregisters cdev and frees major on unload
7. No oops under normal test tool usage

## Suggested device node

After `insmod`, create node if not using `device_create`:

```bash
MAJOR=$(grep learn_buffer /proc/devices | awk '{print $1}')
sudo mknod /dev/learn_buffer c $MAJOR 0
sudo chmod 666 /dev/learn_buffer   # lab VM only
```

## Deliverables

1. **`learn_buffer.ko`** source + Makefile
2. **`MODULE_README.md`**: build, mknod, test sequence
3. **Test log** pasted:

   ```bash
   echo 'hello kernel' | ./test_write /dev/learn_buffer
   ./test_read /dev/learn_buffer
   ```

4. Document partial read/write behavior

## Rubric

| Criterion | Points |
|-----------|--------|
| Module builds and loads | 15 |
| Write then read returns FIFO data | 30 |
| Uses copy_to/from_user correctly | 25 |
| Clean unload (no leaked major/cdev) | 10 |
| User test tools compile with -Wall -Wextra | 10 |
| MODULE_README + test log | 10 |
| **Total** | **100** |

## Worksheet

[9.2-chardev-walkthrough.md](../../labs/phase-09/worksheets/9.2-chardev-walkthrough.md)
