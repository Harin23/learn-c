# Environment Setup (Ubuntu)

This curriculum assumes **Ubuntu Linux** (22.04 LTS or 24.04 LTS recommended) as the primary development environment.

## Required Packages

Install the baseline toolchain and documentation:

```bash
sudo apt update
sudo apt install -y \
    build-essential \
    gdb \
    git \
    manpages-dev \
    linux-tools-common
```

Required before [Phase 2, Module 2.5](../phase-02-memory-core-c/module-02-05-gdb-valgrind-pitfalls/README.md):

```bash
sudo apt install -y valgrind
```

Required for Phase 5:

```bash
sudo apt install -y strace
```

Optional for Phase 5 networking projects:

```bash
sudo apt install -y net-tools curl
```

Optional for Phase 7 code navigation:

```bash
sudo apt install -y ripgrep universal-ctags cscope global
```

Optional for Phase 6:

```bash
sudo apt install -y binutils
sudo apt install -y linux-tools-generic   # perf, optional
```

## Verify Installation

From the repository root:

```bash
./scripts/verify-phase-01.sh   # after Phase 1 setup
./scripts/verify-phase-02.sh   # before Phase 2 (requires Valgrind)
./scripts/verify-phase-03.sh   # before Phase 3
./scripts/verify-phase-04.sh   # before Phase 4
./scripts/verify-phase-05.sh   # before Phase 5
./scripts/verify-phase-06.sh   # before Phase 6
./scripts/verify-phase-07.sh   # before Phase 7
```

Expected output: all checks pass with `OK` messages.

## Manual Verification

```bash
gcc --version          # GCC 11+ (13+ recommended)
gdb --version
git --version
make --version
valgrind --version     # Phase 2.5+
```

## Compiler Flags (Use Always)

For all Phase 1 projects, compile with:

```bash
gcc -Wall -Wextra -std=c11 -g -o program source.c
```

| Flag | Purpose |
|------|---------|
| `-Wall -Wextra` | Enable warnings; treat warnings as bugs |
| `-std=c11` | Use C11 standard |
| `-g` | Include debug symbols for GDB |

## Editor Setup

Any text editor works. Recommended options:

- **VS Code / Cursor** with the C/C++ extension
- **vim** or **neovim**
- **gedit** for beginners

Configure your editor to show line numbers and use spaces or tabs consistently (pick one).

## Man Pages

Learn to read manual pages early:

```bash
man 3 printf     # Library function
man 1 ls         # User command
man 2 open       # System call (Phase 4+)
man 7 signal     # Overview page
```

Section numbers: 1 = user commands, 2 = system calls, 3 = library functions, 7 = overviews.

## Directory for Your Work

You may work directly in this repository or keep projects in a separate directory. If using Git for your projects:

```bash
git init my-project
cd my-project
cp ../learn-c/.gitignore .
```

## Troubleshooting

### `gcc: command not found`

Install build-essential: `sudo apt install build-essential`

### GDB shows `<optimized out>` for variables

Compile with `-g` and without `-O2` while learning: `gcc -g -O0 ...`

### Permission denied running verify script

```bash
chmod +x scripts/verify-phase-01.sh scripts/verify-phase-02.sh scripts/verify-phase-03.sh scripts/verify-phase-04.sh scripts/verify-phase-05.sh scripts/verify-phase-06.sh scripts/verify-phase-07.sh
```

## Next Step

Begin [Phase 1, Module 1.1](../phase-01-programming-foundations/module-01-01-first-c-program/README.md).
