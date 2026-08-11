// Iterative flood fill with an explicit stack. O(rows * cols) time,
// O(rows * cols) space worst case.
//
// Recursion survives here more often than in Python (no 1000-frame limit), but
// a 300x300 snake island is still ~45,000 frames deep, which is close enough to
// the default 8 MB stack that the explicit stack is the safer habit.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size(), cols = grid[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int islands = 0;

        vector<pair<int, int>> stk;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != '1') continue;

                islands++;
                grid[i][j] = '0';  // mark on push, never on pop
                stk.push_back({i, j});

                while (!stk.empty()) {
                    auto [x, y] = stk.back();
                    stk.pop_back();

                    for (int d = 0; d < 4; d++) {
                        int u = x + dx[d], v = y + dy[d];
                        if (u < 0 || u >= rows || v < 0 || v >= cols) continue;
                        if (grid[u][v] != '1') continue;
                        grid[u][v] = '0';
                        stk.push_back({u, v});
                    }
                }
            }
        }

        return islands;
    }
};
