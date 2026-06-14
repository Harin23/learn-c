# Phase 6 Labs

Architecture and OS labs — mix of C programs, shell observation, and written analysis.

| Lab | File | Module |
|-----|------|--------|
| Hello / assembly source | [hello.c](hello.c), [add_regs.c](add_regs.c) | 6.1 |
| Page size | [pagesize_starter.c](pagesize_starter.c) | 6.2 |
| maps parser | [maps_parser_starter.c](maps_parser_starter.c) | 6.2 |
| mmap touch | [mmap_touch_starter.c](mmap_touch_starter.c) | 6.2 |
| FCFS scheduler | [sched_fcfs_starter.c](sched_fcfs_starter.c) | 6.3 |
| Process input | [testdata/processes.txt](testdata/processes.txt) | 6.3 |
| stat compare | [stat_compare_starter.sh](stat_compare_starter.sh) | 6.4 |
| fstat tool | [fstat_starter.c](fstat_starter.c) | 6.4 |
| Cache matrix | [cache_matrix_starter.c](cache_matrix_starter.c) | 6.5 |

```bash
./scripts/verify-phase-06.sh
```

Useful commands:

```bash
gcc -S -O0 -fno-omit-frame-pointer file.c
objdump -d -M intel a.out
cat /proc/self/maps
cat /proc/interrupts
```

Prerequisite: [Phase 5 exit gate](../../phase-05-linux-systems-programming/README.md#phase-exit-gate).
