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

Required for Phase 8 (kernel build and VM boot):

```bash
sudo apt install -y bc bison flex libssl-dev libelf-dev libncurses-dev \
    rsync dwarves qemu-system-x86
```

Optional for Phase 8:

```bash
sudo apt install -y ccache   # faster rebuilds
```

Phase 8 needs **~25 GB free disk** for a kernel tree and build directory, and **8 GB RAM minimum** (16 GB recommended for parallel `make -j`).

Set your local kernel tree before Module 8.2:

```bash
export KERNEL_SRC="$HOME/src/linux"
```

See [resources/phase-08.md](../resources/phase-08.md) for pinned kernel tag and VM setup.

Required for Phase 9 (loadable kernel modules in VM):

- Complete Phase 8 setup first
- Rebuild VM kernel with [labs/phase-09/configs/learn-c-modules.config](../labs/phase-09/configs/learn-c-modules.config) merged into `.config`
- See [resources/phase-09.md](../resources/phase-09.md)

No additional host packages beyond Phase 8 are required for Phase 9.

Optional for Phase 10 (AMD GPU analysis on host — Path A):

```bash
sudo apt install -y mesa-utils vulkan-tools   # glxinfo, vulkaninfo
```

Phase 10 does **not** require AMD hardware; source-only analysis via `$KERNEL_SRC` or Elixir (Path B) is sufficient. See [resources/phase-10.md](../resources/phase-10.md).

Optional for Phase 11 (upstream submission — Path A):

```bash
pip install --user b4          # preferred patch send/receive tool
sudo apt install -y git-email  # optional; git send-email helper
```

Phase 11 does **not** require email setup for Path B (dry-run export). See [resources/phase-11.md](../resources/phase-11.md).

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
./scripts/verify-phase-08.sh   # before Phase 8
./scripts/verify-phase-09.sh   # before Phase 9 (requires Phase 8 + modules config)
./scripts/verify-phase-10.sh   # before Phase 10
./scripts/verify-phase-11.sh   # before Phase 11
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
chmod +x scripts/verify-phase-01.sh scripts/verify-phase-02.sh scripts/verify-phase-03.sh scripts/verify-phase-04.sh scripts/verify-phase-05.sh scripts/verify-phase-06.sh scripts/verify-phase-07.sh scripts/verify-phase-08.sh scripts/verify-phase-09.sh scripts/verify-phase-10.sh scripts/verify-phase-11.sh
```

## Next Step

Begin [Phase 1, Module 1.1](../phase-01-programming-foundations/module-01-01-first-c-program/README.md).
