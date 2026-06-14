#!/usr/bin/env bash
# Verify Phase 7 navigation tools and mini-util build
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PASS=0
FAIL=0

ok() { echo "OK: $1"; PASS=$((PASS + 1)); }
fail() { echo "FAIL: $1" >&2; FAIL=$((FAIL + 1)); }

check() {
	if command -v "$1" >/dev/null 2>&1; then
		ok "$1 found"
	else
		fail "$1 not found — sudo apt install $2"
	fi
}

echo "=== Phase 7 tool checks ==="
check rg ripgrep
check git git
check ctags universal-ctags
check cscope cscope

echo ""
echo "=== mini-util build ==="
if make -C "$ROOT/mini-util" clean all >/dev/null 2>&1; then
	ok "mini-util builds"
else
	fail "mini-util build failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	exit 1
fi

echo "Environment ready for Phase 7."
echo "Note: mini-util tests intentionally fail until Project 41 fixes."
