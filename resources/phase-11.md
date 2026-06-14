# Phase 11 Resources

Canonical reading list for Phase 11 — Open Source Contributions (curriculum finale).

## Pinned Kernel Version

Use the same tag as Phases 8–10 ([resources/phase-08.md](phase-08.md)):

| Item | Value |
|------|-------|
| Recommended tag | `v6.12` |
| checkpatch | `$KERNEL_SRC/scripts/checkpatch.pl` |
| get_maintainer | `$KERNEL_SRC/scripts/get_maintainer.pl` |

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-11.sh
```

## Submission Paths

| Path | Requirements |
|------|----------------|
| **A** | Send to mailing list or Mesa GitLab MR |
| **B** | Dry-run export only — valid for curriculum completion |

Path B is first-class. Employer email policies and list moderation are real barriers.

## Optional Tools (Path A)

| Tool | Install | Notes |
|------|---------|-------|
| **b4** | `pip install --user b4` or distro package | Preferred for kernel patch send/receive |
| **git send-email** | configure `sendemail.*` in git config | See kernel submitting-patches doc |
| **git-email** | `sudo apt install git-email` | Debian helper meta-package |

Kernel doc: [Submitting patches](https://www.kernel.org/doc/html/latest/process/submitting-patches.html)

Do **not** require email setup for Path B.

## Required Reading

| Resource | Modules |
|----------|---------|
| `Documentation/process/submitting-patches.rst` | 11.2, 11.3 |
| `Documentation/process/coding-style.rst` | 11.1, 11.3 |
| `Documentation/process/developer-certificate-of-origin.rst` | 11.2 |
| `MAINTAINERS` (graphics / DRM section) | 11.2 |
| [lore.kernel.org](https://lore.kernel.org) — recent `Documentation/gpu/` threads | 11.2 |

## Module Reading Map

| Module | Focus |
|--------|-------|
| 11.1 | Sample patches, rebase practice, `PATCH_REVIEW_NOTES.md` |
| 11.2 | get_maintainer, cover letter, lore research, `UPSTREAM_SUBMISSION_PLAN.md` |
| 11.3 | checkpatch, Part B execution, `CONTRIBUTION_REPORT.md` |

## Graphics Stack Contribution Targets

| Option | Target | List / MR |
|--------|--------|-----------|
| **A (recommended)** | `Documentation/gpu/` | dri-devel@lists.freedesktop.org |
| **B** | amdgpu/DRM comment in traced file | dri-devel or linux-kernel@vger.kernel.org |
| **C (advanced)** | Mesa docs | [Mesa GitLab](https://gitlab.freedesktop.org/mesa/mesa) |

Must align with `AMDGPU_TRACE.md` Phase 11 preview. **No functional amdgpu driver logic changes.**

## Useful Commands

```bash
# MAINTAINERS routing
cd "$KERNEL_SRC"
scripts/get_maintainer.pl --no-rolestats Documentation/gpu/introduction.rst

# checkpatch on staged diff
git diff | scripts/checkpatch.pl --strict --no-signoff -

# checkpatch on exported patch
scripts/checkpatch.pl --strict --no-signoff 0001-*.patch

# export series
git format-patch -3 HEAD~3

# optional: compare revisions
git range-diff v1..v2
```

## Prior Phase Cross-Links

| Phase | Skill reused in Phase 11 |
|-------|--------------------------|
| 7 | `git format-patch`, patch self-review |
| 8 | checkpatch, Signed-off-by, in-tree patch discipline |
| 9 | Driver context for traced files |
| 10 | `AMDGPU_TRACE.md`, Phase 11 preview section |

## Curriculum Completion

Complete [Phase 11 exit gate](../phase-11-open-source-contributions/README.md#phase-exit-gate):

- Module reports + Project 52 Part B
- [curriculum-completion-checklist.md](../labs/phase-11/checklists/curriculum-completion-checklist.md)
- Phase 11 oral checklist

This completes the **52-project** learn-c curriculum.

## Safety Reminder

Do not submit invasive amdgpu production patches as Part B. Doc and comment fixes only unless you have mentor review and VM validation for anything beyond that scope.
