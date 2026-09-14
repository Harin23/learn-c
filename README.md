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

## Progress Tracker

Tick a box when the work is committed. Module boxes are the gate — only check one after its README's **Exit Criteria** all pass.

### Parts 1–11

Projects for these parts are listed in [docs/project-sequence.md](docs/project-sequence.md). Expand a part and break it into labs/projects when you reach it.

<details open>
<summary><strong>Part 1 — Programming Foundations</strong> (projects 1–7) — <em>you are here</em></summary>

- [x] 1.1 — First C Program, Variables, and Types
  - [x] Lab 1: Toolchain verification (`scripts/verify-part-01.sh`)
  - [x] Lab 2: Format specifier experiments (`module-01-01-first-c-program/format_experiment.c`)
  - [x] Lab 3: Type sizes with `sizeof`
  - [x] Lab 4: Temperature converter
  - [x] Project 1: Unit Converter CLI → `project-repos/project-1`
- [x] 1.2 — Control Flow and Basic I/O
  - [x] Lab 1: FizzBuzz three ways (`module-01-02-control-flow/fizzbuzz.c`)
  - [x] Lab 2: Input sanitizer (`module-01-02-control-flow/input-sanitizer.c`)
  - [x] Lab 3: Line counter (`labs/part-01/line_counter_starter.c`)
  - [x] Project 2: Guess-the-Number Game → `project-repos/project-2`
  - [x] Project 3: Grade Calculator → `project-repos/project-3`
- [ ] 1.3 — Functions and Program Organization
  - [x] Lab 1: Extract math helpers into `.h`/`.c` (`labs/part-01/math_utils_starter/`)
  - [x] Lab 2: Makefile build (`all` + `clean`)
  - [x] Lab 3: Pass-by-value with GDB (`module-01-03-functions/swap-demo.c`)
  - [ ] Project 4: Statistics Library → `project-repos/project-4`
  - [ ] Exit criteria signed off
- [ ] 1.4 — Arrays, Strings, Structs, and Enums
  - [ ] Lab 1: Reverse string in place (`labs/part-01/reverse_string_starter.c`)
  - [ ] Lab 2: CSV line parser (`labs/part-01/sample_contacts.csv`)
  - [ ] Lab 3: Enum state machine
  - [ ] Project 5: Contact Card Manager
  - [ ] Project 6: Word Counter CLI
  - [ ] Exit criteria signed off
- [ ] 1.5 — Basic Debugging and Git Fundamentals
  - [ ] Lab 1: Debug the buggy calculator (`labs/part-01/buggy_calc/`)
  - [ ] Lab 2: Introduce and find an off-by-one bug
  - [ ] Lab 3: Git workflow
  - [ ] Project 7: Student Gradebook capstone (`labs/part-01/gradebook_starter/`)
  - [ ] Exit criteria signed off
- [ ] Part 1 exit gate passed
</details>

<details>
<summary><strong>Part 2 — Memory and Core C</strong> (projects 8–12)</summary>

- [ ] 2.1 — Pointers
- [ ] 2.2 — Dynamic Memory Allocation
- [ ] 2.3 — Memory Layout: Stack vs Heap
- [ ] 2.4 — Function Pointers and Error Handling
- [ ] 2.5 — GDB Deep Dive and Common C Pitfalls
- [ ] Part 2 exit gate passed
</details>

<details>
<summary><strong>Part 3 — Data Structures and Algorithms</strong> (projects 13–18)</summary>

- [ ] 3.1 — Linked Lists, Stacks, and Queues
- [ ] 3.2 — Hash Tables
- [ ] 3.3 — Trees
- [ ] 3.4 — Algorithmic Thinking
- [ ] 3.5 — Performance Analysis
- [ ] Part 3 exit gate passed
</details>

<details>
<summary><strong>Part 4 — Linux User-Space Development</strong> (projects 19–26)</summary>

- [ ] 4.1 — Linux Filesystem and File I/O
- [ ] 4.2 — Processes and Signals
- [ ] 4.3 — Threads
- [ ] 4.4 — Inter-Process Communication
- [ ] 4.5 — Build Systems and Makefiles
- [ ] 4.6 — Static and Shared Libraries
- [ ] Part 4 exit gate passed
</details>

<details>
<summary><strong>Part 5 — Linux Systems Programming</strong> (projects 27–33)</summary>

- [ ] 5.1 — System Calls
- [ ] 5.2 — fork() and exec()
- [ ] 5.3 — pipe() and IPC Patterns
- [ ] 5.4 — pthreads (Advanced)
- [ ] 5.5 — Networking and TCP/IP
- [ ] 5.6 — Event-Driven Programming
- [ ] Part 5 exit gate passed
</details>

<details>
<summary><strong>Part 6 — Computer Architecture and OS</strong> (projects 34–38)</summary>

- [ ] 6.1 — CPU Architecture and Instruction Execution
- [ ] 6.2 — Memory Hierarchy and Virtual Memory
- [ ] 6.3 — Scheduling and Context Switching
- [ ] 6.4 — Filesystems and I/O Subsystems
- [ ] 6.5 — Device Drivers, Interrupts, and Caches
- [ ] Part 6 exit gate passed
</details>

<details>
<summary><strong>Part 7 — Reading Large Codebases</strong> (projects 39–41)</summary>

- [ ] 7.1 — Navigating Open-Source Repositories
- [ ] 7.2 — Linux Source Tree Structure
- [ ] 7.3 — Documentation-Driven Development and Small Fixes
- [ ] Part 7 exit gate passed
</details>

<details>
<summary><strong>Part 8 — Linux Kernel Fundamentals</strong> (projects 42–46)</summary>

- [ ] 8.1 — Kernel Architecture Overview
- [ ] 8.2 — Kernel Build System
- [ ] 8.3 — Kernel Subsystems and APIs
- [ ] 8.4 — Kernel Memory Management and Scheduling
- [ ] 8.5 — Kernel Synchronization
- [ ] Part 8 exit gate passed
</details>

<details>
<summary><strong>Part 9 — Kernel Modules and Drivers</strong> (projects 47–51)</summary>

- [ ] 9.1 — Loadable Kernel Modules
- [ ] 9.2 — Character Devices
- [ ] 9.3 — Sysfs and Procfs
- [ ] 9.4 — Driver Architecture and PCI Devices
- [ ] 9.5 — Hardware Interfaces
- [ ] Part 9 exit gate passed
</details>

<details>
<summary><strong>Part 10 — AMD Driver and Graphics Stack</strong> (project 52 Part A)</summary>

- [ ] 10.1 — Linux Graphics Stack Overview → `GRAPHICS_STACK.md`
- [ ] 10.2 — DRM Subsystem and AMDGPU Architecture → `DRM_AMDGPU_WALK.md`
- [ ] 10.3 — Mesa Overview and GPU Scheduling → `MESA_GPU_PATH.md`
- [ ] 10.4 — Memory Management in Graphics Drivers → `GEM_TTM_ANALYSIS.md`
- [ ] Project 52 Part A — AMDGPU trace → `AMDGPU_TRACE.md`
- [ ] Part 10 exit gate passed
</details>

<details>
<summary><strong>Part 11 — Open Source Contributions</strong> (project 52 Part B)</summary>

- [ ] 11.1 — Patch Workflow and Code Reviews → `PATCH_REVIEW_NOTES.md`
- [ ] 11.2 — Linux Contribution Process → `UPSTREAM_SUBMISSION_PLAN.md`
- [ ] 11.3 — Upstream Development and Git Workflows
- [ ] Project 52 Part B — AMDGPU upstream contribution → `CONTRIBUTION_REPORT.md`
- [ ] Curriculum complete
</details>

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

**Curriculum material:** all 11 parts are fully implemented. Part 11 completes the curriculum with upstream contribution workflow and Project 52 Part B.

**My progress:** see the [Progress Tracker](#progress-tracker) above.
