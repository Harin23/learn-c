# Rebase Practice — Module 11.1 Lab 3

Create a messy three-commit history, then clean it with interactive rebase.

## Setup

```bash
cd labs/part-11/rebase-practice
./setup.sh
cd messy-series
```

This creates a repo with three commits:

1. `add helper` — adds a stub function
2. `fix typo` — fixes a comment (should be squashed into 1)
3. `add docs` — README update (keep separate)

## Exercise

Goal: end with **2 commits** — one for code (helper + typo fix), one for docs.

```bash
git log --oneline
git rebase -i HEAD~3
# use fixup or squash on commit 2 into commit 1
git log --oneline
```

Optional: if you amend the series, compare with:

```bash
git range-diff origin/main HEAD  # after creating a backup branch
```

## Cleanup

```bash
cd ..
rm -rf messy-series
```

Record commands used in [worksheet 11.1](../worksheets/11.1-patch-review-practice.md) Part 3.
