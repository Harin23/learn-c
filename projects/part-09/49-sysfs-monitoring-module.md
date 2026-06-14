# Project 49: Sysfs Monitoring Module

**Module:** 9.3 — Sysfs and Procfs  
**Estimated time:** 10–14 hours

## Description

Extend your Project 48 char device module (or rebuild from [sysfs-stats starter](../../labs/part-09/sysfs-stats/)) to expose read-only statistics and one read-write tunable via sysfs.

## Requirements

1. Sysfs attributes (minimum):
   - `read_count` — read-only, increments on each char dev read
   - `write_count` — read-only, increments on each write
   - `max_buffer_bytes` — read-write, tunable cap ≤ 4096 (validate input)
2. Use `DEVICE_ATTR` or `sysfs_create_file` on appropriate kobject
3. If using `device_create`, attributes under `/sys/class/.../learn_buffer/`
4. All attributes removed on `module_exit` before cdev unregister
5. Document sysfs paths in README

## Optional

- `/proc/learn_c_buffer` seq_file summary (one line: counts + buffer fill level)

## Deliverables

1. **`learn_buffer_sysfs.ko`** (may be same module as Project 48 evolved)
2. **`SYSFS_DOC.md`** containing:
   - Full sysfs paths
   - `cat` output before/after read/write tests
   - `echo 2048 > max_buffer_bytes` test and verification
   - Confirmation files gone after `rmmod`

## Rubric

| Criterion | Points |
|-----------|--------|
| read_count / write_count accurate | 30 |
| max_buffer_bytes tunable with validation | 25 |
| Clean sysfs removal on unload | 20 |
| SYSFS_DOC with real VM output | 15 |
| Worksheet 9.3 completed | 10 |
| **Total** | **100** |

## Worksheet

[9.3-sysfs-tour.md](../../labs/part-09/worksheets/9.3-sysfs-tour.md)
