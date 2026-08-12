// Union-Find. O(rows * cols * a(n)) time, O(rows * cols) space.
// Does not mutate the grid, and extends to "Number of Islands II" where land
// arrives one cell at a time and the count is queried after each addition.
class Solution {
public:
    vector<int> parent, rnk;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // path halving
            x = parent[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (rnk[ra] < rnk[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rnk[ra] == rnk[rb]) rnk[ra]++;
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size(), cols = grid[0].size();
        parent.resize(rows * cols);
        iota(parent.begin(), parent.end(), 0);
        rnk.assign(rows * cols, 0);

        int islands = 0;

        // Only up and left: the down/right pairs get handled from the other side.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != '1') continue;

                islands++;
                int id = i * cols + j;
                if (i > 0 && grid[i - 1][j] == '1' && unite(id - cols, id)) islands--;
                if (j > 0 && grid[i][j - 1] == '1' && unite(id - 1, id)) islands--;
            }
        }

        return islands;
    }
};
