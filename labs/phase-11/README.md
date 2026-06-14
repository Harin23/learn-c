# Phase 11 Labs

Worksheets, checklists, and practice materials for upstream contribution workflow. This phase produces real patches — doc/comment fixes recommended for Project 52 Part B.

## Setup

```bash
export KERNEL_SRC="$HOME/src/linux"
./scripts/verify-phase-11.sh
```

Optional (Path A — actual send):

```bash
pip install --user b4   # or: sudo apt install b4
# configure git send-email — see resources/phase-11.md
```

## Submission Paths

| Path | When to use |
|------|-------------|
| **A** | Send patch to mailing list or open Mesa GitLab MR (mentor approval encouraged) |
| **B** | Full artifact package locally (series + cover letter + CONTRIBUTION_REPORT.md); explicitly not sent — valid for curriculum completion |

## Worksheets

| Worksheet | Module |
|-----------|--------|
| [11.1-patch-review-practice.md](worksheets/11.1-patch-review-practice.md) | 11.1 |
| [11.2-upstream-submission-plan.md](worksheets/11.2-upstream-submission-plan.md) | 11.2 |
| [11.3-contribution-execution.md](worksheets/11.3-contribution-execution.md) | 11.3 |

## Checklists

| Checklist | Use when |
|-----------|----------|
| [upstream-submission-checklist.md](checklists/upstream-submission-checklist.md) | Before sending or exporting Project 52 Part B |
| [curriculum-completion-checklist.md](checklists/curriculum-completion-checklist.md) | Final curriculum sign-off |

## Practice Materials

| Material | Module |
|----------|--------|
| [sample-patches/](sample-patches/) | 11.1 — review lab patches with intentional flaws |
| [rebase-practice/](rebase-practice/) | 11.1 — interactive rebase exercise |
