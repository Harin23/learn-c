# Project Sequence

This curriculum uses **52 small projects** across 11 phases. Each project reinforces concepts from the current module. Complete projects in order unless you have explicit prior experience.

## Phase 1 Projects (Detailed)

| # | Project | Module | Spec |
|---|---------|--------|------|
| 1 | Unit Converter CLI | 1.1 | [01-unit-converter.md](../projects/phase-01/01-unit-converter.md) |
| 2 | Guess-the-Number Game | 1.2 | [02-guess-the-number.md](../projects/phase-01/02-guess-the-number.md) |
| 3 | Grade Calculator | 1.2 | [03-grade-calculator.md](../projects/phase-01/03-grade-calculator.md) |
| 4 | Statistics Library | 1.3 | [04-statistics-library.md](../projects/phase-01/04-statistics-library.md) |
| 5 | Contact Card Manager | 1.4 | [05-contact-card-manager.md](../projects/phase-01/05-contact-card-manager.md) |
| 6 | Word Counter CLI | 1.4 | [06-word-counter.md](../projects/phase-01/06-word-counter.md) |
| 7 | Student Gradebook Capstone | 1.5 | [07-gradebook-capstone.md](../projects/phase-01/07-gradebook-capstone.md) |

## Phase 2 Projects (Detailed)

| # | Project | Module | Spec |
|---|---------|--------|------|
| 8 | Pointer Toolkit | 2.1 | [08-pointer-toolkit.md](../projects/phase-02/08-pointer-toolkit.md) |
| 9 | Dynamic Array (Stretchy Buffer) | 2.2 | [09-dynamic-array.md](../projects/phase-02/09-dynamic-array.md) |
| 10 | Stack Frame Visualizer | 2.3 | [10-stack-visualizer.md](../projects/phase-02/10-stack-visualizer.md) |
| 11 | Callback-Based Menu | 2.4 | [11-callback-menu.md](../projects/phase-02/11-callback-menu.md) |
| 12 | Fix Memory Leaks (Valgrind) | 2.5 | [12-valgrind-fix.md](../projects/phase-02/12-valgrind-fix.md) |

## Phase 3 Projects (Detailed)

| # | Project | Module | Spec |
|---|---------|--------|------|
| 13 | Singly Linked List Toolkit | 3.1 | [13-linked-list-toolkit.md](../projects/phase-03/13-linked-list-toolkit.md) |
| 14 | RPN Calculator | 3.1 | [14-rpn-calculator.md](../projects/phase-03/14-rpn-calculator.md) |
| 15 | Job Queue | 3.1 | [15-job-queue.md](../projects/phase-03/15-job-queue.md) |
| 16 | Simple Hash Map | 3.2 | [16-hash-map.md](../projects/phase-03/16-hash-map.md) |
| 17 | File-System Tree (BST) | 3.3 | [17-bst-filesystem.md](../projects/phase-03/17-bst-filesystem.md) |
| 18 | Sort Benchmark Suite | 3.5 | [18-sort-benchmark.md](../projects/phase-03/18-sort-benchmark.md) |

## Full Project Roadmap (Phases 4–11)

Detailed specs for projects 19–52 will ship with their respective phase expansions.

| # | Project | Phase | Skills |
|---|---------|-------|--------|
| 19 | `cat` clone | 4.1 | file I/O |
| 20 | Log parser | 4.1 | parsing |
| 21 | File organizer | 4.1 | directories |
| 22 | Process viewer | 4.2 | /proc |
| 23 | System monitor | 4.2 | signals |
| 24 | Mini text editor | 4.3 | terminal I/O |
| 25 | Producer-consumer | 4.4 | IPC |
| 26 | Static + shared library demo | 4.6 | linking |
| 27 | Custom shell | 5.2 | fork/exec |
| 28 | Pipe-based filter pipeline | 5.3 | pipes |
| 29 | Thread pool | 5.4 | pthreads |
| 30 | HTTP server | 5.5 | sockets |
| 31 | Chat server | 5.5 | networking |
| 32 | File watcher (inotify) | 5.6 | event-driven |
| 33 | Process manager | 5.6 | syscalls |
| 34–38 | Architecture labs | 6 | OS theory |
| 39–41 | Codebase exploration + fixes | 7 | navigation |
| 42–46 | Kernel build, trace, patches | 8 | kernel |
| 47–51 | LKM, char device, sysfs | 9 | drivers |
| 52 | AMDGPU trace + contribution | 10–11 | upstream |

## Project Sizing Guidelines

- Phase 1 projects: 2–6 hours each (capstone: 6–8 hours)
- Phase 2 projects: 3–6 hours each
- Phase 3 projects: 4–8 hours each (sort benchmark capstone: 6–8 hours)
- Later phase projects: 4–12 hours each
- Favor completing many small projects over one large project per phase

## Submission Checklist (All Projects)

- [ ] Compiles with `-Wall -Wextra -std=c11` with zero warnings
- [ ] Includes a brief README with build/run instructions
- [ ] Handles invalid input without crashing (where applicable)
- [ ] Code is readable with meaningful names
