#!/usr/bin/env bash
# Verify Part 11 upstream contribution environment
set -euo pipefail

REPO="$(cd "$(dirname "$0")/../../.." && pwd)"
LABS="$REPO/labs/part-11"
PASS=0
FAIL=0
WARN=0

ok() { echo "OK: $1"; PASS=$((PASS + 1)); }
fail() { echo "FAIL: $1" >&2; FAIL=$((FAIL + 1)); }
warn() { echo "WARN: $1"; WARN=$((WARN + 1)); }

echo "=== Part 11 lab assets ==="
for f in \
	"$LABS/worksheets/11.1-patch-review-practice.md" \
	"$LABS/worksheets/11.2-upstream-submission-plan.md" \
	"$LABS/worksheets/11.3-contribution-execution.md" \
	"$LABS/checklists/upstream-submission-checklist.md" \
	"$LABS/checklists/curriculum-completion-checklist.md" \
	"$LABS/sample-patches/01-mini-util-style-bug.patch" \
	"$LABS/sample-patches/02-kernel-doc-nits.patch" \
	"$LABS/rebase-practice/setup.sh"
do
	if [ -f "$f" ]; then
		ok "present $(basename "$f")"
	else
		fail "missing $f"
	fi
done

echo ""
echo "=== Core tools ==="
if command -v git >/dev/null 2>&1; then ok "git found"; else fail "git not found"; fi
if command -v rg >/dev/null 2>&1; then ok "rg found"; else warn "rg not found — sudo apt install ripgrep"; fi

echo ""
echo "=== Kernel source (required for checkpatch / get_maintainer) ==="
if [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/scripts/checkpatch.pl" ] 2>/dev/null; then
	ok "KERNEL_SRC=$KERNEL_SRC has checkpatch.pl"
elif [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/Makefile" ]; then
	warn "KERNEL_SRC set but scripts/checkpatch.pl not found"
else
	warn "KERNEL_SRC not set — see resources/part-11.md"
fi

if [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/scripts/get_maintainer.pl" ] 2>/dev/null; then
	ok "get_maintainer.pl available"
else
	warn "get_maintainer.pl not found — set KERNEL_SRC to full kernel tree"
fi

echo ""
echo "=== Optional submission tools (Path A) ==="
if command -v b4 >/dev/null 2>&1; then
	ok "b4 found"
else
	warn "b4 not found — optional; pip install b4 or use dry-run Path B"
fi

if git config --get sendemail.smtpserver >/dev/null 2>&1; then
	ok "git send-email smtpserver configured"
else
	warn "git send-email not configured — Path B dry-run is valid"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS  Failed: $FAIL  Warnings: $WARN"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 11."
echo "Path B (dry-run export) is valid if email tools are unavailable."
