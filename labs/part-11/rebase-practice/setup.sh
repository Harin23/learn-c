#!/usr/bin/env bash
# Create messy-series repo for interactive rebase practice
set -euo pipefail

DIR="$(cd "$(dirname "$0")" && pwd)"
REPO="$DIR/messy-series"

rm -rf "$REPO"
mkdir -p "$REPO/src"
cd "$REPO"

git init -q
git config user.email "practice@learn-c.local"
git config user.name "Learn C Practice"

cat > README.md <<'EOF'
# Rebase practice stub

Temporary repo for Part 11 Module 11.1.
EOF

cat > src/helper.c <<'EOF'
/* Helper for rebase practice */

int helper_add(int a, int b)
{
	/* add two intgers */
	return a + b;
}
EOF

git add README.md src/helper.c
git commit -q -m "add helper"

# Commit 2: typo fix only — candidate for fixup
sed -i 's/intgers/integers/' src/helper.c
git add src/helper.c
git commit -q -m "fix typo"

# Commit 3: docs — keep separate
echo "" >> README.md
echo "See helper_add() in src/helper.c." >> README.md
git add README.md
git commit -q -m "add docs"

echo "Created $REPO with history:"
git log --oneline
