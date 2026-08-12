#include "../../tools/leetcode.h"
#include "solution.cpp"

// Fresh grid per call — numIslands mutates its input.
vector<vector<char>> rows(vector<string> lines) {
    vector<vector<char>> grid;
    for (const string& line : lines) grid.push_back(vector<char>(line.begin(), line.end()));
    return grid;
}

// One island shaped as a single ~n*n/2 long corridor: the input that makes a
// recursive flood fill recurse ~45,000 deep at n = 300.
vector<vector<char>> snake(int n) {
    vector<vector<char>> grid(n, vector<char>(n, '0'));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) grid[i].assign(n, '1');
        else grid[i][(i / 2) % 2 == 0 ? n - 1 : 0] = '1';
    }
    return grid;
}

int main() {
    Solution sol;

    auto g1 = rows({"11110", "11010", "11000", "00000"});
    test(sol.numIslands(g1) == 1, "Example 1");

    auto g2 = rows({"11000", "11000", "00100", "00011"});
    test(sol.numIslands(g2) == 3, "Example 2");

    auto g3 = rows({"1"});
    test(sol.numIslands(g3) == 1, "Single land cell");

    auto g4 = rows({"0"});
    test(sol.numIslands(g4) == 0, "Single water cell");

    auto g5 = rows({"101", "010", "101"});
    test(sol.numIslands(g5) == 5, "Diagonals are not connected");

    auto g6 = rows({"1111111111"});
    test(sol.numIslands(g6) == 1, "Single row");

    auto g7 = rows({"1", "0", "1"});
    test(sol.numIslands(g7) == 2, "Single column");

    auto g8 = snake(300);
    test(sol.numIslands(g8) == 1, "300x300 snake (deep traversal)");

    return summary();
}
