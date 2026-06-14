#!/usr/bin/env bash
# Verify Phase 3 lab starters compile.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/phase-03"
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

echo "=== Phase 3 toolchain checks ==="
check_cmd gcc
check_cmd make
check_cmd valgrind

echo ""
echo "=== Compile Phase 3 lab starters ==="

TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

compile() {
	local src="$1"
	local out="$2"
	if gcc -Wall -Wextra -std=c11 -g -o "$TMPDIR/$out" "$src" 2>"$TMPDIR/compile.err"; then
		ok "compiled $(basename "$src")"
	else
		fail "compile failed for $(basename "$src")"
		cat "$TMPDIR/compile.err" >&2
	fi
}

compile "$LABS/hash_fn_starter.c" hash_fn
compile "$LABS/binary_search_starter.c" binary_search
compile "$LABS/insertion_sort_starter.c" insertion_sort
compile "$LABS/timing_starter.c" timing

for dir in list_starter stack_starter queue_starter hashmap_starter bst_starter merge_sort_starter; do
	if make -C "$LABS/$dir" clean all >/dev/null 2>&1; then
		ok "$dir builds"
	else
		fail "$dir build failed"
	fi
done

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Phase 3."
