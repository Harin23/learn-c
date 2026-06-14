#!/usr/bin/env bash
# Verify Part 9 LKM lab environment
set -euo pipefail

REPO="$(cd "$(dirname "$0")/../../.." && pwd)"
LABS="$REPO/labs/part-09"
PASS=0
FAIL=0
WARN=0

ok() { echo "OK: $1"; PASS=$((PASS + 1)); }
fail() { echo "FAIL: $1" >&2; FAIL=$((FAIL + 1)); }
warn() { echo "WARN: $1"; WARN=$((WARN + 1)); }

echo "=== Part 9 lab assets ==="
for f in \
	"$LABS/configs/learn-c-modules.config" \
	"$LABS/checklists/module-vm-safety-checklist.md" \
	"$LABS/checklists/lkm-review-checklist.md" \
	"$LABS/worksheets/9.1-lkm-build-load.md" \
	"$LABS/worksheets/9.2-chardev-walkthrough.md" \
	"$LABS/worksheets/9.3-sysfs-tour.md" \
	"$LABS/worksheets/9.4-pci-driver-trace.md" \
	"$LABS/worksheets/9.5-irq-mmio-scavenger.md" \
	"$LABS/hello-lkm/Makefile" \
	"$LABS/hello-lkm/hello_lkm.c" \
	"$LABS/chardev-buffer/Makefile" \
	"$LABS/pci-skeleton/learn_pci_demo.c" \
	"$LABS/user-tools/test_read.c" \
	"$LABS/user-tools/test_write.c"
do
	if [ -f "$f" ]; then
		ok "present $(basename "$f")"
	else
		fail "missing $f"
	fi
done

echo ""
echo "=== User-space test tools compile ==="
TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

if gcc -Wall -Wextra -std=c11 -o "$TMPDIR/test_read" "$LABS/user-tools/test_read.c" 2>/dev/null; then
	ok "test_read.c compiles"
else
	fail "test_read.c compile failed"
fi

if gcc -Wall -Wextra -std=c11 -o "$TMPDIR/test_write" "$LABS/user-tools/test_write.c" 2>/dev/null; then
	ok "test_write.c compiles"
else
	fail "test_write.c compile failed"
fi

echo ""
echo "=== Part 8 toolchain (required for modules) ==="
if [ -x "$REPO/labs/part-08/scripts/setup-kernel-build.sh" ]; then
	if "$REPO/labs/part-08/scripts/setup-kernel-build.sh" >/dev/null 2>&1; then
		ok "Part 8 kernel build tools available"
	else
		warn "Part 8 toolchain incomplete — run verify-part-08.sh"
	fi
else
	warn "Part 8 setup script not found"
fi

echo ""
echo "=== Kernel source (optional module build) ==="
if [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/Makefile" ]; then
	ok "KERNEL_SRC=$KERNEL_SRC"
	if make -C "$KERNEL_SRC" M="$LABS/hello-lkm" modules >/dev/null 2>&1; then
		ok "hello-lkm builds against KERNEL_SRC"
		make -C "$KERNEL_SRC" M="$LABS/hello-lkm" clean >/dev/null 2>&1 || true
	else
		warn "hello-lkm build failed — check KERNEL_SRC and Part 8 tree"
	fi
else
	warn "KERNEL_SRC not set — set before building modules (see resources/part-09.md)"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS  Failed: $FAIL  Warnings: $WARN"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 9."
echo "Merge learn-c-modules.config into VM kernel before Module 9.1."
echo "Read labs/part-09/checklists/module-vm-safety-checklist.md before insmod."
