from typing import List


class Solution:
    """Recursive flood fill. O(rows * cols) time, O(rows * cols) recursion depth.

    Depth equals the size of the largest island, so a pathological input — one
    island winding through most of a 300x300 grid — would exceed CPython's
    default 1000-frame limit. LeetCode's test data for this problem does not
    contain one. See solution2.py for the union-find variant, which has no
    depth bound at all.
    """

    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])

        def dfs(x: int, y: int) -> None:
            grid[x][y] = "0"  # mark on entry, before recursing
            for u, v in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                if 0 <= u < rows and 0 <= v < cols and grid[u][v] == "1":
                    dfs(u, v)

        islands = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    islands += 1
                    dfs(i, j)

        return islands
