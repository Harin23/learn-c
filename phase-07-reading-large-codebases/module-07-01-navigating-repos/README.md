# Module 7.1 — Navigating Open-Source Repositories

**Estimated time:** 12–15 hours

## Learning Objectives

By the end of this module you will be able to:

- Orient yourself in a new repository using README, docs, and build files
- Search code effectively with ripgrep and ctags/cscope
- Use Git history (`log`, `blame`, `show`) to understand why code exists
- Trace execution flow from `main` through key functions in user-space projects
- Document findings in structured exploration reports

## Prerequisites

- [Phase 5 exit gate](../../phase-05-linux-systems-programming/README.md#phase-exit-gate)

## Concepts to Study

1. **Repository landmarks** — README, INSTALL, CONTRIBUTING, Makefile, meson.build, .github/
2. **Code search** — `rg`, `git grep`, case sensitivity, regex boundaries
3. **Symbol navigation** — `ctags -R`, `:tag` in vim, `cscope`
4. **Git archaeology** — `git log -L`, `git blame`, bisect preview
5. **Build graph** — what targets exist; how to compile one binary
6. **Coding conventions** — Linux kernel style vs GNU vs project-specific
7. **Issue trackers** — reading bugs before code
8. **Dependency direction** — who calls whom; draw call graphs

## Hands-On Labs

### Lab 1: Toolchain Setup

Run [labs/phase-07/scripts/setup-tools.sh](../../labs/phase-07/scripts/setup-tools.sh) and verify `rg`, `ctags`, `cscope` work.

### Lab 2: mini-util Orientation

Explore [labs/phase-07/mini-util/](../../labs/phase-07/mini-util/): build, run tests, generate tags.

Worksheet: [labs/phase-07/worksheets/7.1-mini-util-orientation.md](../../labs/phase-07/worksheets/7.1-mini-util-orientation.md)

### Lab 3: Clone and Build External Project

Choose one:

- **coreutils** (single command): `wc` or `cat` source path
- **util-linux**: `dmesg` or `kill` subset
- **toybox** (smaller): one applet

Follow upstream build docs; build only what you need if possible.

### Lab 4: blame and log

Pick one function in external project; run `git blame` and `git log -p -- path` — write 5-line history summary.

## Mini-Project

**User-Space Codebase Archaeology** — [projects/phase-07/39-userspace-archaeology.md](../../projects/phase-07/39-userspace-archaeology.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| [Pro Git](https://git-scm.com/book) Ch. 2, 5, 9 | History, debugging |
| `man rg`, `man ctags` | Tool reference |
| [How to Read Other People's Code](https://journal.stuffwithstuff.com/2016/06/16/how-do-you-read-other-peoples-code/) | Mindset |

## Exit Criteria

Before advancing to Module 7.2, confirm:

- [ ] Can build mini-util and external project from docs
- [ ] Worksheet 7.1 completed
- [ ] Project 39 report includes call graph for one command
- [ ] You used both ripgrep and ctags/cscope successfully

## Next Module

[Module 7.2 — Linux Source Tree Structure](../module-07-02-linux-source-tree/README.md)
