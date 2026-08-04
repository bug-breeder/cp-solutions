from collections import deque
from typing import List


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        n, m = len(grid), len(grid[0])
        sx = sy = target_mask = 0

        for i in range(n):
            for j in range(m):
                c = grid[i][j]
                if c == '@':
                    sx, sy = i, j
                elif 'a' <= c <= 'f':
                    target_mask |= 1 << (ord(c) - ord('a'))

        dist = [[[-1] * 64 for _ in range(m)] for _ in range(n)]
        dist[sx][sy][0] = 0
        q = deque([(sx, sy, 0)])

        while q:
            x, y, mask = q.popleft()
            cur_dist = dist[x][y][mask]

            if mask == target_mask:
                return cur_dist

            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                u, v = x + dx, y + dy
                if not (0 <= u < n and 0 <= v < m):
                    continue
                c = grid[u][v]
                if c == '#':
                    continue
                new_mask = mask
                if 'a' <= c <= 'f':
                    new_mask |= 1 << (ord(c) - ord('a'))
                if 'A' <= c <= 'F' and not (mask & (1 << (ord(c) - ord('A')))):
                    continue
                if dist[u][v][new_mask] != -1:
                    continue
                dist[u][v][new_mask] = cur_dist + 1
                q.append((u, v, new_mask))

        return -1
