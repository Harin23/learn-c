# Project 41: Small Patch Submission (Phase 7 Capstone)

**Module:** 7.3 — Documentation-Driven Development and Small Fixes  
**Estimated time:** 8–12 hours

## Description

Fix a beginner-friendly bug or improve documentation with tests, producing a proper Git patch series ready for review.

## Option A — mini-util (recommended first)

Repository: [labs/phase-07/mini-util/](../../labs/phase-07/mini-util/)

1. Read [ISSUES.md](../../labs/phase-07/mini-util/ISSUES.md)
2. Pick issue `#1` or `#2` (or both as two commits)
3. Add/update test in `tests/run_tests.sh`
4. Fix code; all tests pass
5. Export patch: `git format-patch -1 HEAD` or `-2` for test+fix

## Option B — Real upstream (advanced)

With instructor/self approval, submit to:

- Documentation fix in kernel `Documentation/` (typo/clarity)
- [kernel-newbie-friendly issues](https://github.com/sjp38/linux) style projects
- Your own Phase 1–6 project README improvement in learn-c (meta)

Document upstream URL and submission method (PR link or mailing list draft).

## Deliverables

1. **Patch file(s)** — `0001-*.patch` with Signed-off-by line (optional but good habit):

   ```
   Signed-off-by: Your Name <email@example.com>
   ```

2. **PATCH_NOTES.md** containing:
   - Problem description
   - Solution approach
   - Test evidence (`tests/run_tests.sh` output)
   - Self-review using [patch-review-checklist.md](../../labs/phase-07/checklists/patch-review-checklist.md)

3. **Commit messages** — imperative subject ≤72 chars; body explains why

## Rubric

| Criterion | Points |
|-----------|--------|
| Bug fixed or docs clearly improved | 25 |
| Test added or updated | 25 |
| Patch format correct | 20 |
| Commit message quality | 15 |
| PATCH_NOTES + checklist complete | 15 |
| **Total** | **100** |

## Example commit message

```
mu-wc: fix word count on trailing spaces

The previous loop counted an extra word when input ended with
multiple spaces. Add regression test and align logic with wc(1).

Fixes: mini-util issue #1
```

## Phase 7 Completion

Projects 39–41 complete Phase 7. Phase 8 requires Phase 6 + Phase 7.
