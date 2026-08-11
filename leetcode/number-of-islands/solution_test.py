import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from typing import List
from tools.leetcode import test, summary
from solution import Solution
from solution2 import Solution as SolutionUF


def rows(*lines: str) -> List[List[str]]:
    """Fresh grid per call — numIslands mutates its input."""
    return [list(line) for line in lines]


def snake(n: int) -> List[List[str]]:
    """One island shaped as a single ~n*n/2 long corridor.

    Recursive DFS bottoms out at Python's 1000-frame limit on this input.
    """
    grid = [["0"] * n for _ in range(n)]
    for i in range(n):
        if i % 2 == 0:
            for j in range(n):
                grid[i][j] = "1"
        else:
            grid[i][n - 1 if (i // 2) % 2 == 0 else 0] = "1"
    return grid


for name, sol in (("dfs", Solution()), ("union-find", SolutionUF())):
    test(sol.numIslands(rows("11110", "11010", "11000", "00000")), 1, f"[{name}] Example 1")
    test(sol.numIslands(rows("11000", "11000", "00100", "00011")), 3, f"[{name}] Example 2")
    test(sol.numIslands(rows("1")), 1, f"[{name}] Single land cell")
    test(sol.numIslands(rows("0")), 0, f"[{name}] Single water cell")
    test(sol.numIslands(rows("101", "010", "101")), 5, f"[{name}] Diagonals are not connected")
    test(sol.numIslands(rows("1111111111")), 1, f"[{name}] Single row")
    test(sol.numIslands([["1"], ["0"], ["1"]]), 2, f"[{name}] Single column")
    test(sol.numIslands(snake(300)), 1, f"[{name}] 300x300 snake (no recursion limit)")

summary()
