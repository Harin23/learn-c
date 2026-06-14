#!/usr/bin/env bash
# Lab 6.4 — compare stat on small vs large files
set -euo pipefail

small=$(mktemp)
large=$(mktemp)
trap 'rm -f "$small" "$large"' EXIT

echo x > "$small"
dd if=/dev/zero of="$large" bs=1024 count=1024 status=none

echo "=== small file ==="
stat "$small"
echo "=== large file (1 MiB) ==="
stat "$large"

echo "inode small: $(stat -c '%i' "$small")"
echo "blocks small: $(stat -c '%b' "$small")"
echo "blocks large: $(stat -c '%b' "$large")"
