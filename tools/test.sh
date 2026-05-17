#!/usr/bin/env bash
set -euo pipefail

PROBLEM="${1:?Usage: test.sh <problem-name> [cpp|py|both]}"
LANG="${2:-both}"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"

run_cpp() {
    local test_file="$ROOT/leetcode/$PROBLEM/solution_test.cpp"
    [[ ! -f "$test_file" ]] && { echo "  (no solution_test.cpp)"; return 0; }
    echo "=== C++ ==="
    local bin
    bin="$(mktemp)"
    g++ -std=c++20 -O2 "$test_file" -o "$bin" && "$bin"; local rc=$?
    rm -f "$bin"
    return $rc
}

run_py() {
    local test_file="$ROOT/leetcode/$PROBLEM/solution_test.py"
    [[ ! -f "$test_file" ]] && { echo "  (no solution_test.py)"; return 0; }
    echo "=== Python ==="
    (cd "$ROOT/leetcode/$PROBLEM" && python3 solution_test.py)
}

case "$LANG" in
    cpp)  run_cpp ;;
    py)   run_py  ;;
    both) run_cpp; run_py ;;
    *)    echo "Lang must be: cpp | py | both"; exit 1 ;;
esac
