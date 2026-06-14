#!/usr/bin/env bash
# Verify Part 10 graphics analysis environment
set -euo pipefail

REPO="$(cd "$(dirname "$0")/../../.." && pwd)"
LABS="$REPO/labs/part-10"
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
		warn "$1 not found (optional for Path B) — $2"
	fi
}

echo "=== Part 10 lab assets ==="
for f in \
	"$LABS/worksheets/10.1-graphics-stack-tour.md" \
	"$LABS/worksheets/10.2-drm-amdgpu-tree.md" \
	"$LABS/worksheets/10.3-mesa-scheduling.md" \
	"$LABS/worksheets/10.4-gem-ttm-tour.md" \
	"$LABS/checklists/graphics-trace-checklist.md"
do
	if [ -f "$f" ]; then
		ok "present $(basename "$f")"
	else
		fail "missing $f"
	fi
done

echo ""
echo "=== Part 7 navigation tools ==="
if command -v rg >/dev/null 2>&1; then ok "rg found"; else warn "rg not found — sudo apt install ripgrep"; fi
if command -v git >/dev/null 2>&1; then ok "git found"; else fail "git not found"; fi

echo ""
echo "=== Optional graphics tools (Path A) ==="
check_cmd glxinfo "sudo apt install mesa-utils"
check_cmd vulkaninfo "sudo apt install vulkan-tools"

echo ""
echo "=== DRM sysfs (Path A hint) ==="
if [ -d /sys/class/drm ] && [ -n "$(ls -A /sys/class/drm 2>/dev/null)" ]; then
	ok "/sys/class/drm present"
else
	warn "no /sys/class/drm — use Path B (source-only) for reports"
fi

echo ""
echo "=== Kernel source (recommended) ==="
if [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/drivers/gpu/drm/amdgpu/amdgpu_drv.c" ] 2>/dev/null; then
	ok "KERNEL_SRC=$KERNEL_SRC has amdgpu tree"
elif [ -n "${KERNEL_SRC:-}" ] && [ -f "$KERNEL_SRC/Makefile" ]; then
	warn "KERNEL_SRC set but amdgpu path not found — check tag or tree"
else
	warn "KERNEL_SRC not set — see resources/part-10.md"
fi

echo ""
echo "=== Summary ==="
echo "Passed: $PASS  Failed: $FAIL  Warnings: $WARN"

if [ "$FAIL" -gt 0 ]; then
	echo "Fix failures above, then re-run this script."
	exit 1
fi

echo "Environment ready for Part 10."
echo "Path B (Elixir-only) is valid if AMD GPU is unavailable."
