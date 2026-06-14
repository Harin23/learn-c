#!/usr/bin/env bash
# Verify Part 5 lab starters compile.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LABS="$ROOT/labs/part-05"
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
		fail "$1 not found (optional: sudo apt install $2)"
	fi
}

echo "=== Part 5 toolchain checks ==="
check_cmd gcc ""
check_cmd make ""
check_cmd strace strace

echo ""
echo "=== Compile Part 5 lab starters ==="

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

compile "$LABS/errno_starter.c" errno
compile "$LABS/fork_starter.c" fork
compile "$LABS/exec_starter.c" exec
compile "$LABS/pipe_fork_starter.c" pipe_fork
compile "$LABS/dup2_starter.c" dup2
compile "$LABS/condvar_starter.c" condvar "-pthread"
compile "$LABS/echo_server_starter.c" echo_server
compile "$LABS/echo_client_starter.c" echo_client
compile "$LABS/http_parse_starter.c" http_parse
compile "$LABS/select_starter.c" select
compile "$LABS/inotify_starter.c" inotify

if make -C "$LABS/tpool_starter" clean all >/dev/null 2>&1; then
	ok "tpool_starter builds"
else
	fail "tpool_starter build failed"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 5."
