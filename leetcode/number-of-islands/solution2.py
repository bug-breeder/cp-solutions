from typing import List


class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x: int) -> int:
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]  # path halving
            x = self.parent[x]
        return x

    def union(self, a: int, b: int) -> bool:
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.rank[ra] < self.rank[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        if self.rank[ra] == self.rank[rb]:
            self.rank[ra] += 1
        return True


class Solution:
    """Union-Find. O(rows * cols * a(n)) time, O(rows * cols) space.

    Slower than flood fill in practice and it does not mutate the grid, but it
    is the approach that extends to "Number of Islands II" (land added one cell
    at a time, report the count after each addition) — flood fill has to redo
    the whole sweep per query, union-find just unions the new cell's neighbours.

    Only the up and left neighbours are scanned: by the time cell (i, j) is
    reached, the down/right pairs will be handled from the other side.
    """

    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])
        dsu = DSU(rows * cols)
        islands = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] != "1":
                    continue

                islands += 1
                if i > 0 and grid[i - 1][j] == "1" and dsu.union((i - 1) * cols + j, i * cols + j):
                    islands -= 1
                if j > 0 and grid[i][j - 1] == "1" and dsu.union(i * cols + j - 1, i * cols + j):
                    islands -= 1

        return islands
