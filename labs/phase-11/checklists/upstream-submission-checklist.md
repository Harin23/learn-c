# Upstream Submission Checklist — Phase 11

Use before sending or exporting Project 52 Part B. Extends [Phase 8 kernel patch checklist](../../phase-08/checklists/kernel-patch-review-checklist.md).

## Trace alignment

- [ ] Patch targets a file or doc section referenced in `AMDGPU_TRACE.md`
- [ ] `CONTRIBUTION_REPORT.md` links to trace step number
- [ ] Scope matches Phase 10 preview (no scope creep into driver logic)

## Scope and safety

- [ ] Doc/comment fix only — no functional amdgpu behavior change
- [ ] One logical change per commit (1–3 commits total)
- [ ] No drive-by whitespace or unrelated file changes
- [ ] VM boot **not** required for doc-only Option A (note if Option B code comments)

## Kernel style

- [ ] `checkpatch.pl --strict` run on full series; issues fixed or documented
- [ ] Follows `Documentation/process/coding-style.rst` for any `.c` / `.h` touched
- [ ] Commit subject ≤72 characters, imperative mood, correct subsystem prefix

## Patch metadata

- [ ] `Signed-off-by: Your Name <email@example.com>` on every commit
- [ ] Body explains **why**, not only what
- [ ] Cover letter drafted (Path A and Path B)
- [ ] `get_maintainer.pl` output saved or referenced in plan

## Submission path

- [ ] Path A or Path B documented in `CONTRIBUTION_REPORT.md`
- [ ] Path A: lore.kernel.org link or Mesa MR URL attached
- [ ] Path B: full series + cover letter exported; dry-run steps documented

## Reviewer mindset

- [ ] Would a maintainer understand this without a verbal explanation?
- [ ] Is this minimal for the stated goal?
- [ ] Revision log included (even if v1 only)

## Sign-off

Part B option chosen: _______________  
checkpatch warnings remaining: _______________  
Path A link or Path B dry-run: _______________
