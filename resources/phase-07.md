# Phase 7 Resources

Canonical reading list for Phase 7 — Reading Large Codebases.

## Mindset and Method

| Resource | Notes |
|----------|-------|
| [How Do You Read Other People's Code?](https://journal.stuffwithstuff.com/2016/06/16/how-do-you-read-other-peoples-code/) | Strategy |
| [Pro Git](https://git-scm.com/book/en/v2) | Ch. 5 (distributed), 9 (history) |
| [Linux Kernel Development](https://lwn.net/Kernel/LDD3/) (Love) | Subsystem overview — not line-by-line |

## Tools

```bash
sudo apt install ripgrep universal-ctags cscope global git
```

| Tool | Use |
|------|-----|
| `rg pattern` | Fast repo search |
| `ctags -R` | Jump to definitions |
| `cscope -R` | Call graph exploration |
| `git log -L :func:file.c` | Function history |
| [Elixir Bootlin](https://elixir.bootlin.com/linux/latest/source) | Kernel browse without full clone |

## Kernel Documentation (read before Phase 8)

- `Documentation/admin-guide/README.rst`
- `Documentation/process/coding-style.rst`
- `Documentation/process/submitting-patches.rst`
- `MAINTAINERS` file in kernel root

## User-Space Projects for Archaeology (Project 39)

| Project | Clone |
|---------|-------|
| coreutils | https://git.savannah.gnu.org/git/coreutils.git |
| util-linux | https://github.com/util-linux/util-linux |
| toybox | https://github.com/landley/toybox |

Start shallow: `git clone --depth=1 <url>`

## Module Reading Map

| Module | Focus |
|--------|-------|
| 7.1 | Pro Git, ripgrep, ctags, mini-util worksheet |
| 7.2 | Love Ch. 2–6, Elixir, MAINTAINERS, worksheet 7.2 |
| 7.3 | submitting-patches.rst, patch checklist, Project 41 |

## Gate to Phase 8

Phase 8 builds and modifies the kernel. Phase 7 ensures you can **read** it first — trace syscalls, find subsystems, and submit readable patches.

Complete Phase 6 in parallel or before Phase 8 if not done yet.
