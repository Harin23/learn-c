#!/usr/bin/env bash
# mini-util regression tests — some fail until ISSUES are fixed
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

make -s all

pass=0
fail=0

ok() {
	echo "PASS: $1"
	pass=$((pass + 1))
}

bad() {
	echo "FAIL: $1"
	fail=$((fail + 1))
}

# Basic wc sanity
out=$(printf 'one two\n' | ./mu-wc -w)
if [ "$out" -eq 2 ]; then
	ok "wc_two_words"
else
	bad "wc_two_words (got $out)"
fi

# Issue #1 — trailing spaces
out=$(printf 'hello  ' | ./mu-wc -w)
if [ "$out" -eq 1 ]; then
	ok "wc_trailing_spaces"
else
	bad "wc_trailing_spaces (got $out, expected 1 — fix ISSUE #1)"
fi

# Basic cat
tmp=$(mktemp)
echo hello > "$tmp"
out=$(./mu-cat "$tmp")
if [ "$out" = "hello" ]; then
	ok "cat_hello"
else
	bad "cat_hello"
fi
rm -f "$tmp"

# Issue #2 — long line
long=$(python3 -c "print('A'*200)")
tmp2=$(mktemp)
printf '%s\n' "$long" > "$tmp2"
out=$(./mu-cat "$tmp2" | wc -c)
if [ "$out" -eq 201 ]; then
	ok "cat_long_line"
else
	bad "cat_long_line (got $out bytes, expected 201 — fix ISSUE #2)"
fi
rm -f "$tmp2"

echo "---"
echo "Passed: $pass Failed: $fail"

if [ "$fail" -gt 0 ]; then
	echo "Fix issues in ISSUES.md for Project 41"
	exit 1
fi

echo "All tests passed"
