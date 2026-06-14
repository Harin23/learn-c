# Report: Patch Review Practice

**Module:** 11.1 — Patch Workflow and Code Reviews  
**Estimated time:** 8–10 hours

## Description

Review two provided sample patches with constructive, prioritized feedback. Document rebase practice and review vocabulary. Builds on Part 7 self-review and Part 8 kernel patch checklist — now from a **reviewer** perspective.

## Prerequisites

- Worksheet [11.1-patch-review-practice.md](../../labs/part-11/worksheets/11.1-patch-review-practice.md)
- Sample patches in [labs/part-11/sample-patches/](../../labs/part-11/sample-patches/)
- Rebase exercise from [rebase-practice/setup.sh](../../labs/part-11/rebase-practice/setup.sh)

## Deliverable: `PATCH_REVIEW_NOTES.md`

### 1. Sample patch A review

Review [01-mini-util-style-bug.patch](../../labs/part-11/sample-patches/01-mini-util-style-bug.patch)

- Minimum **3 actionable comments** with severity (must-fix / nit / question)
- One paragraph: would you accept this patch as-is? Why or why not?

### 2. Sample patch B review

Review [02-kernel-doc-nits.patch](../../labs/part-11/sample-patches/02-kernel-doc-nits.patch)

- Minimum **3 actionable comments** with severity
- One paragraph: what would you ask the author to revise before sending upstream?

### 3. Rebase practice summary

- Original vs final commit count
- Commands used (`git rebase -i`, fixup/squash)
- One sentence: when is rebase preferred over merge for patch cleanup?

### 4. Review vocabulary

Define must-fix, nit, and question in your own words (2–3 sentences each).

### 5. Connection to prior parts

One paragraph linking Part 7 [patch-review-checklist.md](../../labs/part-07/checklists/patch-review-checklist.md) and Part 8 [kernel-patch-review-checklist.md](../../labs/part-08/checklists/kernel-patch-review-checklist.md) to how you reviewed these patches.

## Rubric

| Criterion | Points |
|-----------|--------|
| Patch A: ≥3 actionable comments with severity | 25 |
| Patch B: ≥3 actionable comments with severity | 25 |
| Rebase practice documented | 20 |
| Vocabulary + prior part connection | 15 |
| Worksheet 11.1 completed | 15 |
| **Total** | **100** |

## Note

Do not apply sample patches to real projects. They contain intentional flaws for learning.

## Next

[Module 11.2 — Linux Contribution Process](../../part-11-open-source-contributions/module-11-02-linux-contribution-process/README.md)
