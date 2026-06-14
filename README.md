# C Programming and Linux Systems Curriculum

A project-based curriculum that takes you from zero C knowledge to reading Linux source code, understanding operating system internals, navigating the kernel, exploring AMD driver architecture, and contributing to open-source Linux projects.

**Primary environment:** Ubuntu Linux  
**Estimated total time:** ~710–865 hours across 52 modules (11 parts)

## How to Use This Repository

1. Read [docs/environment-setup.md](docs/environment-setup.md) and run the verification script.
2. Start with [part-01-programming-foundations/](part-01-programming-foundations/) and work modules in order.
3. Complete every lab and mini-project before advancing.
4. Pass each module's exit criteria checklist before moving to the next module.
5. Do not skip parts — later content assumes earlier foundations.

## Curriculum Roadmap

| Part | Title | Modules | Hours |
|------|-------|---------|-------|
| 1 | [Programming Foundations](part-01-programming-foundations/) | 5 | 60–75 |
| 2 | [Memory and Core C](part-02-memory-core-c/) | 5 | 65–80 |
| 3 | [Data Structures and Algorithms](part-03-data-structures-algorithms/) | 5 | 70–85 |
| 4 | [Linux User-Space Development](part-04-linux-user-space/) | 6 | 85–100 |
| 5 | [Linux Systems Programming](part-05-linux-systems-programming/) | 6 | 90–105 |
| 6 | [Computer Architecture and OS](part-06-computer-architecture-os/) | 5 | 70–85 |
| 7 | [Reading Large Codebases](part-07-reading-large-codebases/) | 3 | 35–45 |
| 8 | [Linux Kernel Fundamentals](part-08-linux-kernel-fundamentals/) | 5 | 75–90 |
| 9 | [Kernel Modules and Drivers](part-09-kernel-modules-drivers/) | 5 | 75–90 |
| 10 | [AMD Driver and Graphics Stack](part-10-amd-driver-graphics/) | 4 | 50–65 |
| 11 | [Open Source Contributions](part-11-open-source-contributions/) | 3 | 35–45 |

**Pace guidance:** At 10 hrs/week ≈ 14–18 months; at 20 hrs/week ≈ 7–9 months.

## Documentation

- [Dependency graph and part gates](docs/dependency-graph.md)
- [Project sequence (all 52 projects)](docs/project-sequence.md)
- [Environment setup (Ubuntu)](docs/environment-setup.md)

## Repository Layout

```
learn-c/
├── docs/                    # Cross-cutting documentation
├── part-01-.../            # Part directories with module READMEs
├── labs/                    # Starter code for hands-on labs
├── projects/                # Project specs and rubrics
├── resources/               # Reading lists per part
└── scripts/                 # Verification and utility scripts
```

## Philosophy

- Build practical skills before theory whenever possible.
- Use project-based learning with many small projects.
- Emphasize understanding how computers actually work.
- Progress from user-space development to kernel-space development.
- Do not introduce kernel development until all required foundations are mastered.

## Current Status

**All 11 parts are fully implemented.** Part 11 completes the curriculum with upstream contribution workflow and Project 52 Part B.
