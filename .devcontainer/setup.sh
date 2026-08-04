#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "==> Installing C++ toolchain and shell utilities"
sudo apt-get update
sudo apt-get install -y --no-install-recommends \
  build-essential gdb cmake ripgrep fzf jq

echo "==> Installing Claude Code CLI"
npm install -g @anthropic-ai/claude-code

echo "==> Installing rtk (Rust Token Killer)"
curl -fsSL https://raw.githubusercontent.com/rtk-ai/rtk/refs/heads/master/install.sh | sh

echo "==> Applying baseline Claude Code configuration"
mkdir -p "$HOME/.claude"
if [ ! -f "$HOME/.claude/settings.json" ]; then
  cp "$SCRIPT_DIR/claude/settings.json" "$HOME/.claude/settings.json"
fi

if [ ! -f "CLAUDE.md" ]; then
  cp "$SCRIPT_DIR/claude/CLAUDE.md" "CLAUDE.md"
fi
