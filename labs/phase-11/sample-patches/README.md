# Sample Patches for Review Lab (Module 11.1)

These patches are **intentionally flawed** for review practice. Do not apply them to real projects.

## How to use

1. Read each patch with `git apply --stat` or open in your editor
2. Write review comments using severity labels: **must-fix**, **nit**, **question**
3. Record findings in [worksheet 11.1](../worksheets/11.1-patch-review-practice.md)

## Patch A — `01-mini-util-style-bug.patch`

**Context:** User-space fix for a word-count utility (mini-util style).

**Intentional flaws to find (do not peek until you try):**

- Vague subject line (missing component prefix)
- Missing `Signed-off-by`
- Drive-by whitespace change in unrelated file
- Fix does not address root cause completely
- No test added
- Commit message body missing "why"

## Patch B — `02-kernel-doc-nits.patch`

**Context:** Documentation clarity fix in `Documentation/gpu/`.

**Intentional flaws to find:**

- Subject line too long (>72 chars)
- Missing `Signed-off-by`
- Wraps at wrong column in body
- Minor factual imprecision (GEM described incorrectly)
- Includes unrelated formatting change in adjacent paragraph

## Answer key

Instructors may use the flaw list above. Students should find at least 3 issues per patch without the answer key.
