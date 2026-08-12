// Recursive flood fill. O(rows * cols) time, O(rows * cols) recursion depth.
// Depth equals the size of the largest island; at the 300x300 constraint limit
// that is ~45,000 frames, which the default 8 MB stack absorbs.
class Solution {
public:
    int rows = 0, cols = 0;

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';  // mark on entry, before recursing
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++) {
            int u = x + dx[d], v = y + dy[d];
            if (u < 0 || u >= rows || v < 0 || v >= cols) continue;
            if (grid[u][v] != '1') continue;
            dfs(grid, u, v);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
