#!/usr/bin/env bash
# Verify Phase 1 toolchain and compile lab starters.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/phase-01"
PASS=0
FAIL=0

ok() {
	echo "OK: $1"
	PASS=$((PASS + 1))
}

fail() {
	echo "FAIL: $1" >&2
	FAIL=$((FAIL + 1))
}

check_cmd() {
	if command -v "$1" >/dev/null 2>&1; then
		ok "$1 found ($("$1" --version 2>&1 | head -1))"
	else
		fail "$1 not found — install via docs/environment-setup.md"
	fi
}

echo "=== Toolchain checks ==="
check_cmd gcc
check_cmd gdb
check_cmd git
check_cmd make

echo ""
echo "=== Compile lab starters ==="

TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

compile() {
	local src="$1"
	local out="$2"
	if gcc -Wall -Wextra -std=c11 -o "$TMPDIR/$out" "$src" 2>"$TMPDIR/compile.err"; then
		ok "compiled $(basename "$src")"
	else
		fail "compile failed for $(basename "$src")"
		cat "$TMPDIR/compile.err" >&2
	fi
}

compile "$LABS/hello.c" hello
compile "$LABS/line_counter_starter.c" line_counter
compile "$LABS/reverse_string_starter.c" reverse
compile "$LABS/math_utils_starter/math_demo.c" math_demo

if make -C "$LABS/buggy_calc" clean all >/dev/null 2>&1; then
	ok "buggy_calc builds"
else
	fail "buggy_calc build failed"
fi

if make -C "$LABS/gradebook_starter" clean all >/dev/null 2>&1; then
	ok "gradebook_starter builds"
else
	fail "gradebook_starter build failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Phase 1."
