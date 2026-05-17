// BFS with state = (row, col, keyMask). O(n * m * 2^k) time.
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sx = 0, sy = 0, targetMask = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                if (c == '@') { sx = i; sy = j; }
                else if ('a' <= c && c <= 'f') targetMask |= 1 << (c - 'a');
            }
        }

        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};

        // dist[row][col][keyMask]
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(64, -1)));

        queue<tuple<int, int, int>> q;
        q.push({sx, sy, 0});
        dist[sx][sy][0] = 0;

        while (!q.empty()) {
            auto [x, y, mask] = q.front(); q.pop();

            int curDist = dist[x][y][mask];
            if (mask == targetMask) return curDist;

            for (int i = 0; i < 4; i++) {
                int u = x + dx[i], v = y + dy[i];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;

                char c = grid[u][v];
                if (c == '#') continue;

                int newMask = mask;
                if ('a' <= c && c <= 'f') newMask |= 1 << (c - 'a');
                if ('A' <= c && c <= 'F' && !(mask & (1 << (c - 'A')))) continue;

                if (dist[u][v][newMask] != -1) continue;
                dist[u][v][newMask] = curDist + 1;
                q.push({u, v, newMask});
            }
        }

        return -1;
    }
};
