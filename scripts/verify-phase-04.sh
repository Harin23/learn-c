#!/usr/bin/env bash
# Verify Phase 4 lab starters compile.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/phase-04"
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

echo "=== Phase 4 toolchain checks ==="
check_cmd gcc
check_cmd make

echo ""
echo "=== Compile Phase 4 lab starters ==="

TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

compile() {
	local extra="${3:-}"
	if gcc -Wall -Wextra -std=c11 -g $extra -o "$TMPDIR/$2" "$1" 2>"$TMPDIR/compile.err"; then
		ok "compiled $(basename "$1")"
	else
		fail "compile failed for $(basename "$1")"
		cat "$TMPDIR/compile.err" >&2
	fi
}

compile "$LABS/copy_starter.c" copy
compile "$LABS/listdir_starter.c" listdir
compile "$LABS/log_parse_starter.c" log_parse
compile "$LABS/proc_self_starter.c" proc_self
compile "$LABS/proc_stat_starter.c" proc_stat
compile "$LABS/signal_starter.c" signal
compile "$LABS/pthread_hello_starter.c" pthread_hello "-pthread"
compile "$LABS/pthread_counter_starter.c" pthread_counter "-pthread"
compile "$LABS/termios_starter.c" termios
compile "$LABS/pipe_starter.c" pipe

if make -C "$LABS/shm_starter" clean all >/dev/null 2>&1; then
	ok "shm_starter builds"
else
	fail "shm_starter build failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Phase 4."
