// Permutation + BFS approach: try all orderings of keys, BFS between each pair.
// O(k! * k * n * m * 2^k) time — feasible only for small k.
class Solution {
public:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    bool isUpper(char c) { return 'A' <= c && c <= 'Z'; }
    bool isLower(char c) { return 'a' <= c && c <= 'z'; }

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<char> keys;
        unordered_map<char, pair<int, int>> pos;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                if (c == '@') pos[c] = {i, j};
                else if (isLower(c)) { keys.push_back(c); pos[c] = {i, j}; }
                else if (isUpper(c)) pos[c] = {i, j};
            }
        }

        sort(keys.begin(), keys.end());
        int k = keys.size();

        unordered_map<char, int> keyId;
        for (int i = 0; i < k; i++) keyId[keys[i]] = i;

        unordered_map<string, int> memo;

        auto getMemoKey = [&](char from, char to, int mask) {
            return string(1, from) + string(1, to) + "#" + to_string(mask);
        };

        auto canPass = [&](char c, int mask) {
            if (c == '#') return false;
            if (isUpper(c)) {
                char key = c - 'A' + 'a';
                if (!keyId.count(key)) return false;
                if ((mask & (1 << keyId[key])) == 0) return false;
            }
            return true;
        };

        auto shortestPath = [&](char fromChar, char toChar, int mask) {
            string memoKey = getMemoKey(fromChar, toChar, mask);
            if (memo.count(memoKey)) return memo[memoKey];

            auto st = pos[fromChar];
            auto en = pos[toChar];

            queue<pair<int, int>> q;
            vector<vector<int>> dist(n, vector<int>(m, -1));
            q.push(st);
            dist[st.first][st.second] = 0;

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x == en.first && y == en.second) return memo[memoKey] = dist[x][y];

                for (int i = 0; i < 4; i++) {
                    int u = x + dx[i], v = y + dy[i];
                    if (u < 0 || u >= n || v < 0 || v >= m) continue;
                    if (dist[u][v] != -1) continue;
                    if (!canPass(grid[u][v], mask)) continue;
                    dist[u][v] = dist[x][y] + 1;
                    q.push({u, v});
                }
            }

            return memo[memoKey] = INT_MAX;
        };

        int result = INT_MAX;

        do {
            char cur = '@';
            int mask = 0, curLen = 0;
            bool valid = true;

            for (char key : keys) {
                int dis = shortestPath(cur, key, mask);
                if (dis == INT_MAX) { valid = false; break; }
                curLen += dis;
                if (curLen >= result) { valid = false; break; }
                mask |= 1 << keyId[key];
                cur = key;
            }

            if (valid) result = min(result, curLen);
        } while (next_permutation(keys.begin(), keys.end()));

        return result == INT_MAX ? -1 : result;
    }
};
