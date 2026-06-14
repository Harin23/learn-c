#!/usr/bin/env bash
# Verify Part 6 lab starters compile.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/part-06"
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
		ok "$1 found"
	else
		fail "$1 not found"
	fi
}

echo "=== Part 6 toolchain checks ==="
check_cmd gcc
check_cmd objdump

echo ""
echo "=== Compile Part 6 lab starters ==="

TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

compile() {
	if gcc -Wall -Wextra -std=c11 -g -o "$TMPDIR/$2" "$1" 2>"$TMPDIR/compile.err"; then
		ok "compiled $(basename "$1")"
	else
		fail "compile failed for $(basename "$1")"
		cat "$TMPDIR/compile.err" >&2
	fi
}

compile "$LABS/hello.c" hello
compile "$LABS/add_regs.c" add_regs
compile "$LABS/pagesize_starter.c" pagesize
compile "$LABS/maps_parser_starter.c" maps_parser
compile "$LABS/mmap_touch_starter.c" mmap_touch
compile "$LABS/sched_fcfs_starter.c" sched_fcfs
compile "$LABS/fstat_starter.c" fstat
compile "$LABS/cache_matrix_starter.c" cache_matrix

if bash "$LABS/stat_compare_starter.sh" >/dev/null 2>&1; then
	ok "stat_compare_starter.sh runs"
else
	fail "stat_compare_starter.sh failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 6."
