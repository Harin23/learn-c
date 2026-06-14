#!/usr/bin/env bash
# Verify Part 8 kernel build environment
set -euo pipefail

REPO="$(cd "$(dirname "$0")/../../.." && pwd)"
LABS="$REPO/labs/part-08"
PASS=0
FAIL=0
WARN=0

ok() { echo "OK: $1"; PASS=$((PASS + 1)); }
fail() { echo "FAIL: $1" >&2; FAIL=$((FAIL + 1)); }
warn() { echo "WARN: $1"; WARN=$((WARN + 1)); }

check_cmd() {
	if command -v "$1" >/dev/null 2>&1; then
		ok "$1 found"
	else
		fail "$1 not found — sudo apt install $2"
	fi
}

echo "=== Part 8 toolchain checks ==="
check_cmd make make
check_cmd gcc build-essential
check_cmd flex flex
check_cmd bison bison
check_cmd bc bc
check_cmd rsync rsync
check_cmd openssl libssl-dev

if pkg-config --exists libelf 2>/dev/null; then
	ok "libelf found (pkg-config)"
else
	fail "libelf not found — sudo apt install libelf-dev"
fi

if pkg-config --exists ncurses 2>/dev/null || [ -f /usr/include/ncurses.h ]; then
	ok "ncurses found (menuconfig)"
else
	fail "ncurses not found — sudo apt install libncurses-dev"
fi

check_cmd qemu-system-x86_64 qemu-system-x86

if command -v ccache >/dev/null 2>&1; then
	ok "ccache found (optional)"
else
	warn "ccache not installed (optional speedup)"
fi

if command -v pahole >/dev/null 2>&1; then
	ok "pahole found (optional, dwarves package)"
else
	warn "pahole not installed (optional — sudo apt install dwarves)"
fi

echo ""
echo "=== Part 8 lab assets ==="
for f in \
	"$LABS/configs/learn-c-base.config" \
	"$LABS/checklists/vm-safety-checklist.md" \
	"$LABS/checklists/kernel-patch-review-checklist.md" \
	"$LABS/worksheets/8.1-boot-log-analysis.md" \
	"$LABS/worksheets/8.2-kbuild-tour.md" \
	"$LABS/worksheets/8.3-coding-style-lab.md" \
	"$LABS/worksheets/8.4-mm-sched-kernel-tour.md" \
	"$LABS/worksheets/8.5-locking-scavenger-hunt.md" \
	"$LABS/scripts/qemu-boot-test.sh.template"
do
	if [ -f "$f" ]; then
		ok "present $(basename "$f")"
	else
		fail "missing $f"
	fi
done

echo ""
echo "=== Kernel source (optional) ==="
if [ -n "${KERNEL_SRC:-}" ] && [ -d "$KERNEL_SRC" ]; then
	if [ -f "$KERNEL_SRC/Makefile" ] && grep -q '^VERSION' "$KERNEL_SRC/Makefile" 2>/dev/null; then
		ok "KERNEL_SRC=$KERNEL_SRC looks like kernel tree"
	else
		warn "KERNEL_SRC set but may not be kernel root"
	fi
else
	warn "KERNEL_SRC not set or missing — clone kernel before Module 8.2 (see resources/part-08.md)"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS  Failed: $FAIL  Warnings: $WARN"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 8."
echo "Read labs/part-08/checklists/vm-safety-checklist.md before booting a custom kernel."
