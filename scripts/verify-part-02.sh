#!/usr/bin/env bash
# Verify Part 2 toolchain, Valgrind, and compile lab starters.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/part-02"
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
		fail "$1 not found"
	fi
}

echo "=== Part 2 toolchain checks ==="
check_cmd gcc
check_cmd gdb
check_cmd make

if command -v valgrind >/dev/null 2>&1; then
	ok "valgrind found ($(valgrind --version 2>&1 | head -1))"
else
	fail "valgrind not found — sudo apt install valgrind"
fi

echo ""
echo "=== Compile Part 2 lab starters ==="

TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

compile() {
	local src="$1"
	local out="$2"
	local extra="${3:-}"
	if gcc -Wall -Wextra -std=c11 -g $extra -o "$TMPDIR/$out" "$src" 2>"$TMPDIR/compile.err"; then
		ok "compiled $(basename "$src")"
	else
		fail "compile failed for $(basename "$src")"
		cat "$TMPDIR/compile.err" >&2
	fi
}

compile "$LABS/pointer_basics_starter.c" pointer_basics
compile "$LABS/swap_starter.c" swap
compile "$LABS/grow_array_starter.c" grow_array
compile "$LABS/memory_addresses_starter.c" memory_addresses
compile "$LABS/fn_ptr_calc_starter.c" fn_ptr_calc
compile "$LABS/buffer_overflow_demo.c" overflow

if make -C "$LABS/darray_starter" clean all >/dev/null 2>&1; then
	ok "darray_starter builds"
else
	fail "darray_starter build failed"
fi

if make -C "$LABS/leaky" clean all >/dev/null 2>&1; then
	ok "leaky builds (bugs intentional — Valgrind should report errors)"
else
	fail "leaky build failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 2."
