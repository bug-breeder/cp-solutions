# Modern C++ Syntax for LeetCode

This is a practical C++ guide for solving LeetCode-style problems. It focuses on syntax, standard library tools, and patterns you will actually use.

Assume LeetCode usually gives you something like:

```cpp
class Solution {
public:
    int solve(vector<int>& nums) {
        // your code
    }
};
```

Most LeetCode environments support at least C++17.

---

## 1. Basic Structure

### Includes

On LeetCode, you usually do not need includes, but locally you can use:

```cpp
#include <bits/stdc++.h>
using namespace std;
```

For production-style C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
```

### Function

```cpp
int add(int a, int b) {
    return a + b;
}
```

### Class

```cpp
class Solution {
public:
    int twoSumStyle(vector<int>& nums) {
        return nums.size();
    }
};
```

### Main function

Usually unnecessary on LeetCode.

```cpp
int main() {
    vector<int> nums = {1, 2, 3};
    cout << nums[0] << endl;
}
```

---

## 2. Core Types

```cpp
int x = 5;
long long big = 10000000000LL;
double d = 3.14;
char c = 'a';
bool ok = true;
string s = "hello";
```

### Common integer limits

```cpp
INT_MAX
INT_MIN
LLONG_MAX
LLONG_MIN
```

Usually from:

```cpp
#include <climits>
```

### Prefer long long for overflow-prone arithmetic

```cpp
long long sum = 0;
for (int x : nums) {
    sum += x;
}
```

---

## 3. References and Const

### Pass by value

Makes a copy.

```cpp
void f(vector<int> nums) {
    nums.push_back(10);
}
```

### Pass by reference

Modifies original, avoids copy.

```cpp
void f(vector<int>& nums) {
    nums.push_back(10);
}
```

### Pass by const reference

Avoids copy, cannot modify.

```cpp
void f(const vector<int>& nums) {
    cout << nums.size();
}
```

For LeetCode helpers, this is common:

```cpp
bool isValid(const string& s) {
    return !s.empty();
}
```

---

## 4. auto

Let the compiler infer the type.

```cpp
auto x = 5;              // int
auto s = string("abc");  // string
```

Very useful with iterators and maps:

```cpp
unordered_map<string, int> freq;
for (auto& [key, value] : freq) {
    cout << key << " " << value << endl;
}
```

Use references when you want to avoid copying:

```cpp
for (auto& x : nums) {
    x++;
}
```

Use const references when reading:

```cpp
for (const auto& word : words) {
    cout << word << endl;
}
```

---

## 5. Vectors

`vector` is the most-used container.

```cpp
vector<int> nums;
vector<int> nums2 = {1, 2, 3};
vector<int> a(5);        // {0,0,0,0,0}
vector<int> b(5, -1);    // {-1,-1,-1,-1,-1}
```

### Common operations

```cpp
nums.push_back(10);
nums.pop_back();
int n = nums.size();
bool empty = nums.empty();
int first = nums.front();
int last = nums.back();
nums.clear();
```

### Indexing

```cpp
nums[0] = 100;
```

No bounds checking. This can crash if index is invalid.

### Looping

```cpp
for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << endl;
}
```

Safer with signed index:

```cpp
int n = nums.size();
for (int i = 0; i < n; i++) {
    cout << nums[i] << endl;
}
```

Range loop:

```cpp
for (int x : nums) {
    cout << x << endl;
}
```

Modify elements:

```cpp
for (int& x : nums) {
    x *= 2;
}
```

---

## 6. 2D Vectors

```cpp
vector<vector<int>> grid;
```

Create m x n grid filled with zero:

```cpp
int m = 3, n = 4;
vector<vector<int>> grid(m, vector<int>(n, 0));
```

Access:

```cpp
grid[0][1] = 5;
```

Loop:

```cpp
for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
        cout << grid[r][c] << " ";
    }
}
```

Directions:

```cpp
vector<pair<int, int>> dirs = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
for (auto [dr, dc] : dirs) {
    int nr = r + dr;
    int nc = c + dc;
}
```

Or arrays:

```cpp
int dirs[5] = {0, 1, 0, -1, 0};
for (int k = 0; k < 4; k++) {
    int nr = r + dirs[k];
    int nc = c + dirs[k + 1];
}
```

---

## 7. Strings

```cpp
string s = "leetcode";
```

### Common operations

```cpp
int n = s.size();
char c = s[0];
s.push_back('x');
s.pop_back();
s += "abc";
```

### Substring

```cpp
string t = s.substr(2, 3); // start at index 2, length 3
string u = s.substr(2);    // from index 2 to end
```

### Find

```cpp
int pos = s.find("code");
if (pos != string::npos) {
    // found
}
```

Technically find returns `size_t`, but this is common:

```cpp
size_t pos = s.find("abc");
```

### Convert string to number

```cpp
int x = stoi("123");
long long y = stoll("1234567890123");
double z = stod("3.14");
```

### Convert number to string

```cpp
string s = to_string(123);
```

### Character helpers

```cpp
isdigit(c)
isalpha(c)
isalnum(c)
islower(c)
isupper(c)
tolower(c)
toupper(c)
```

Usually cast to avoid edge cases:

```cpp
char lower = tolower((unsigned char)c);
```

For LeetCode, people often write:

```cpp
char lower = tolower(c);
```

---

## 8. Pairs

```cpp
pair<int, int> p = {3, 5};
cout << p.first;
cout << p.second;
```

Structured binding:

```cpp
auto [a, b] = p;
```

Vector of pairs:

```cpp
vector<pair<int, int>> intervals;
intervals.push_back({1, 3});
intervals.push_back({2, 6});
```

Sort pairs naturally by first, then second:

```cpp
sort(intervals.begin(), intervals.end());
```

---

## 9. Tuples

Less common, but useful.

```cpp
tuple<int, int, string> t = {1, 2, "abc"};
auto [x, y, name] = t;
```

Priority queue sometimes uses tuples:

```cpp
priority_queue<tuple<int, int, int>> pq;
pq.push({dist, row, col});
```

---

## 10. Arrays

### Fixed-size C-style array

```cpp
int arr[5] = {0};
```

### std::array

```cpp
array<int, 26> freq{};
freq[0]++;
```

Great for character frequency:

```cpp
array<int, 26> count{};
for (char c : s) {
    count[c - 'a']++;
}
```

---

## 11. Sorting

```cpp
sort(nums.begin(), nums.end());
```

Descending:

```cpp
sort(nums.rbegin(), nums.rend());
```

Custom comparator:

```cpp
sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
    return a[0] < b[0];
});
```

Sort by second element:

```cpp
sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
});
```

Sort descending by value:

```cpp
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a > b;
});
```

### Important comparator rule

Comparator should answer: "should `a` come before `b`?"

Do not use `<=`.

Bad:

```cpp
return a <= b;
```

Good:

```cpp
return a < b;
```

---

## 12. Reverse

```cpp
reverse(nums.begin(), nums.end());
reverse(s.begin(), s.end());
```

---

## 13. Min and Max

```cpp
int a = min(x, y);
int b = max(x, y);
```

For multiple values:

```cpp
int m = min({a, b, c});
int M = max({a, b, c});
```

Vector min/max:

```cpp
int mn = *min_element(nums.begin(), nums.end());
int mx = *max_element(nums.begin(), nums.end());
```

---

## 14. Accumulate

Sum:

```cpp
int sum = accumulate(nums.begin(), nums.end(), 0);
```

Use `0LL` for long long result:

```cpp
long long sum = accumulate(nums.begin(), nums.end(), 0LL);
```

This matters. If you use `0`, the accumulation is done as `int`.

---

## 15. Binary Search

### Manual binary search

```cpp
int l = 0, r = nums.size() - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        l = mid + 1;
    } else {
        r = mid - 1;
    }
}
return -1;
```

### Lower bound

First position where value is >= target.

```cpp
auto it = lower_bound(nums.begin(), nums.end(), target);
int index = it - nums.begin();
```

### Upper bound

First position where value is > target.

```cpp
auto it = upper_bound(nums.begin(), nums.end(), target);
int index = it - nums.begin();
```

### Check if found

```cpp
auto it = lower_bound(nums.begin(), nums.end(), target);
if (it != nums.end() && *it == target) {
    // found
}
```

---

## 16. Maps

### unordered_map

Hash map. Average O(1).

```cpp
unordered_map<int, int> freq;
freq[5]++;
freq[10] = 3;
```

Check if key exists:

```cpp
if (freq.count(x)) {
    // exists
}
```

Or:

```cpp
if (freq.find(x) != freq.end()) {
    // exists
}
```

Loop:

```cpp
for (auto& [key, value] : freq) {
    cout << key << " " << value << endl;
}
```

Erase:

```cpp
freq.erase(x);
```

### map

Ordered map. O(log n). Keys sorted.

```cpp
map<int, int> mp;
mp[3] = 10;
mp[1] = 20;
```

Iteration gives sorted keys.

```cpp
for (auto& [k, v] : mp) {
    cout << k << " " << v << endl;
}
```

### When to use which?

Use `unordered_map` for frequency/counting/lookup.

Use `map` when you need sorted order.

---

## 17. Sets

### unordered_set

```cpp
unordered_set<int> seen;
seen.insert(5);
if (seen.count(5)) {
    // exists
}
seen.erase(5);
```

### set

Sorted unique values.

```cpp
set<int> s;
s.insert(3);
s.insert(1);
s.insert(2);
for (int x : s) {
    cout << x << endl; // 1, 2, 3
}
```

### Lower bound in set

```cpp
auto it = s.lower_bound(x);
if (it != s.end()) {
    cout << *it;
}
```

---

## 18. Stack

Last in, first out.

```cpp
stack<int> st;
st.push(1);
st.push(2);
int top = st.top();
st.pop();
bool empty = st.empty();
int size = st.size();
```

Common for parentheses, monotonic stack, DFS.

Example:

```cpp
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

---

## 19. Queue

First in, first out.

```cpp
queue<int> q;
q.push(1);
q.push(2);
int front = q.front();
q.pop();
bool empty = q.empty();
```

Common for BFS.

```cpp
queue<int> q;
q.push(start);
while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int nei : graph[node]) {
        q.push(nei);
    }
}
```

---

## 20. Deque

Double-ended queue.

```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();
int a = dq.front();
int b = dq.back();
```

Common for sliding window maximum.

---

## 21. Priority Queue / Heap

Default is max heap.

```cpp
priority_queue<int> pq;
pq.push(5);
pq.push(1);
pq.push(10);
int largest = pq.top(); // 10
pq.pop();
```

### Min heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Heap of pairs

```cpp
priority_queue<pair<int, int>> pq;
pq.push({dist, node});
```

Default compares first, then second.

### Min heap of pairs

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

Common for Dijkstra:

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push({0, source});
while (!pq.empty()) {
    auto [dist, node] = pq.top();
    pq.pop();
}
```

### Custom comparator

For structs:

```cpp
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // min heap by first
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
```

For `priority_queue`, the comparator feels backwards: return `true` if `a` has lower priority than `b`.

---

## 22. Lambda Functions

Useful for custom sorting, DFS helpers, and small local logic.

```cpp
auto add = [](int a, int b) {
    return a + b;
};
int x = add(2, 3);
```

Capture outside variables:

```cpp
int offset = 10;
auto f = [&](int x) {
    return x + offset;
};
```

- Capture by reference: `[&]`
- Capture by value: `[=]`

---

## 23. Recursive Lambdas

In C++17, the easiest LeetCode style is:

```cpp
function<int(int)> dfs = [&](int node) {
    int result = 1;
    for (int nei : graph[node]) {
        result += dfs(nei);
    }
    return result;
};
```

For grid DFS:

```cpp
function<void(int, int)> dfs = [&](int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (grid[r][c] == 0) return;
    grid[r][c] = 0;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
};
```

---

## 24. Structs

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

### TreeNode

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
```

---

## 25. Pointers

LeetCode linked lists and trees use pointers.

```cpp
ListNode* node = new ListNode(5);
```

Access members:

```cpp
node->val
node->next
```

Equivalent to `(*node).val`.

Check null:

```cpp
if (node == nullptr) {
    return;
}
```

Often shortened:

```cpp
if (!node) {
    return;
}
```

---

## 26. Linked List Patterns

### Traverse

```cpp
ListNode* cur = head;
while (cur) {
    cout << cur->val;
    cur = cur->next;
}
```

### Dummy node

Extremely useful.

```cpp
ListNode dummy(0);
ListNode* tail = &dummy;
while (head) {
    tail->next = head;
    tail = tail->next;
    head = head->next;
}
return dummy.next;
```

### Reverse linked list

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
```

### Fast and slow pointers

```cpp
ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

---

## 27. Tree Traversal

### DFS recursive

```cpp
void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->left);
    dfs(root->right);
}
```

### Inorder

```cpp
void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
```

### BFS level order

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
```

---

## 28. Graph Representation

### Adjacency list

```cpp
int n = 5;
vector<vector<int>> graph(n);
graph[0].push_back(1);
graph[1].push_back(2);
```

For undirected graph:

```cpp
graph[u].push_back(v);
graph[v].push_back(u);
```

### Weighted graph

```cpp
vector<vector<pair<int, int>>> graph(n);
graph[u].push_back({v, weight});
```

Loop:

```cpp
for (auto [nei, weight] : graph[node]) {
    // use nei and weight
}
```

---

## 29. DFS Graph

```cpp
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int node) {
    visited[node] = true;
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            dfs(nei);
        }
    }
}
```

Or lambda:

```cpp
function<void(int)> dfs = [&](int node) {
    visited[node] = true;
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            dfs(nei);
        }
    }
};
```

---

## 30. BFS Graph

```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(0);
visited[0] = true;
while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            visited[nei] = true;
            q.push(nei);
        }
    }
}
```

---

## 31. Dijkstra

```cpp
vector<int> dist(n, INT_MAX);
dist[src] = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push({0, src});
while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    if (d > dist[node]) continue;
    for (auto [nei, weight] : graph[node]) {
        if (dist[node] + weight < dist[nei]) {
            dist[nei] = dist[node] + weight;
            pq.push({dist[nei], nei});
        }
    }
}
```

With overflow safety:

```cpp
vector<long long> dist(n, LLONG_MAX);
dist[src] = 0;
```

---

## 32. Union Find / DSU

```cpp
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
        return true;
    }
};
```

Usage:

```cpp
DSU dsu(n);
dsu.unite(0, 1);
if (dsu.find(0) == dsu.find(1)) {
    // connected
}
```

---

## 33. Dynamic Programming Vectors

### 1D DP

```cpp
vector<int> dp(n, 0);
dp[0] = 1;
for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + 1;
}
```

### 2D DP

```cpp
vector<vector<int>> dp(m, vector<int>(n, 0));
```

### Initialize with large value

```cpp
const int INF = 1e9;
vector<int> dp(n, INF);
```

For long long:

```cpp
const long long INF = 4e18;
vector<long long> dp(n, INF);
```

---

## 34. Memoization

```cpp
vector<int> memo(n, -1);
function<int(int)> solve = [&](int i) {
    if (i == n) return 0;
    if (memo[i] != -1) return memo[i];
    int ans = solve(i + 1);
    return memo[i] = ans;
};
```

For 2D memo:

```cpp
vector<vector<int>> memo(m, vector<int>(n, -1));
function<int(int, int)> dp = [&](int i, int j) {
    if (i == m || j == n) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = max(dp(i + 1, j), dp(i, j + 1));
};
```

---

## 35. Modulo Arithmetic

```cpp
const int MOD = 1e9 + 7;
```

Addition:

```cpp
x = (x + y) % MOD;
```

Multiplication needs long long:

```cpp
x = (1LL * x * y) % MOD;
```

Avoid negative modulo bugs:

```cpp
x = ((x - y) % MOD + MOD) % MOD;
```

---

## 36. Bit Manipulation

### Basic operators

```cpp
a & b   // AND
a | b   // OR
a ^ b   // XOR
~a      // NOT
a << k  // shift left
a >> k  // shift right
```

### Check if bit is set

```cpp
if (mask & (1 << i)) {
    // bit i is set
}
```

For large shifts: `1LL << i`

### Set / Clear / Toggle a bit

```cpp
mask |= (1 << i);   // set
mask &= ~(1 << i);  // clear
mask ^= (1 << i);   // toggle
```

### Count set bits

```cpp
int cnt = __builtin_popcount(mask);
int cnt = __builtin_popcountll(mask); // for long long
```

### Lowest set bit

```cpp
int lowbit = x & -x;
```

### Iterate over all subsets

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // i is included
        }
    }
}
```

### Iterate over submasks

```cpp
for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // sub is a non-empty submask of mask
}
```

Include empty submask:

```cpp
for (int sub = mask; ; sub = (sub - 1) & mask) {
    // use sub
    if (sub == 0) break;
}
```

---

## 37. Common Algorithms

```cpp
int c = count(nums.begin(), nums.end(), target);

auto it = find(nums.begin(), nums.end(), target);
if (it != nums.end()) {
    int index = it - nums.begin();
}

bool allPositive = all_of(nums.begin(), nums.end(), [](int x) { return x > 0; });
bool hasZero = any_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
```

### unique (remove consecutive duplicates after sorting)

```cpp
sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());
```

### next_permutation

```cpp
sort(nums.begin(), nums.end());
do {
    // use nums
} while (next_permutation(nums.begin(), nums.end()));
```

---

## 38. Erase Syntax

```cpp
nums.erase(nums.begin() + i);              // one position, O(n)
nums.erase(nums.begin() + l, nums.begin() + r);  // range [l, r)
nums.erase(remove(nums.begin(), nums.end(), val), nums.end());  // erase-remove idiom
```

---

## 39. Custom Hash for Pair

`unordered_map<pair<int,int>, int>` does not work by default.

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
unordered_map<pair<int, int>, int, PairHash> mp;
unordered_set<pair<int, int>, PairHash> st;
```

Or encode pair into long long:

```cpp
long long key = ((long long)x << 32) ^ y;
```

---

## 40. Comparators for LeetCode

```cpp
// Sort intervals by start
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
});

// Sort by length
sort(words.begin(), words.end(), [](const string& a, const string& b) {
    return a.size() < b.size();
});

// Sort descending frequency
sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    return a.second > b.second;
});

// Sort by frequency descending, value ascending
sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
});
```

---

## 41. Common Type Aliases

```cpp
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
```

---

## 42. Constants

```cpp
const int INF = 1e9;
const long long LINF = 4e18;
const int MOD = 1e9 + 7;

// Class-level:
static constexpr int MOD = 1000000007;
```

---

## 43. size_t vs int

`vector.size()` returns `size_t` (unsigned). Avoid bugs with reverse loops:

```cpp
// Bug when nums is empty:
for (int i = nums.size() - 1; i >= 0; i--) { ... }

// Safe:
int n = nums.size();
for (int i = n - 1; i >= 0; i--) { ... }
```

---

## 44. Important Casting

```cpp
long long product = 1LL * a * b;
double avg = (double)sum / n;
int x = (int)s.size();
// Modern style:
int x = static_cast<int>(s.size());
```

---

## 45. Common Math Functions

```cpp
abs(x), sqrt(x), pow(a, b), ceil(x), floor(x), log(x)
```

Prefer shifts for powers of two:

```cpp
int x = 1 << 10; // 2^10
```

---

## 46. GCD and LCM (C++17)

```cpp
int g = gcd(a, b);
int l = lcm(a, b);

// Manual LCM to avoid overflow:
long long l = 1LL * a / gcd(a, b) * b;
```

---

## 47. Off-by-One Patterns

Half-open interval `[l, r)`:

```cpp
for (int i = l; i < r; i++) { ... }  // length = r - l
```

Inclusive interval `[l, r]`:

```cpp
for (int i = l; i <= r; i++) { ... }  // length = r - l + 1
```

---

## 48. Binary Search on Answer

Find minimum valid answer:

```cpp
int l = 1, r = 1e9;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (can(mid)) r = mid;
    else l = mid + 1;
}
return l;
```

Find maximum valid answer:

```cpp
int l = 0, r = 1e9;
while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (can(mid)) l = mid;
    else r = mid - 1;
}
return l;
```

---

## 49. Sliding Window

```cpp
int left = 0, sum = 0, ans = 0;
for (int right = 0; right < nums.size(); right++) {
    sum += nums[right];
    while (sum > target) {
        sum -= nums[left++];
    }
    ans = max(ans, right - left + 1);
}
```

---

## 50. Prefix Sum

```cpp
int n = nums.size();
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
// Sum of [l, r]: prefix[r + 1] - prefix[l]
```

---

## 51. Difference Array

Range update `[l, r]` by `val`:

```cpp
vector<int> diff(n + 1, 0);
diff[l] += val;
diff[r + 1] -= val;

// Build final array:
int cur = 0;
for (int i = 0; i < n; i++) {
    cur += diff[i];
    arr[i] = cur;
}
```

---

## 52. Monotonic Stack

Next greater element:

```cpp
vector<int> ans(n, -1);
stack<int> st; // stores indices
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
        ans[st.top()] = nums[i];
        st.pop();
    }
    st.push(i);
}
```

---

## 53. Monotonic Queue

Sliding window maximum:

```cpp
deque<int> dq; // stores indices
vector<int> ans;
for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
}
```

---

## 54. Backtracking

```cpp
vector<vector<int>> ans;
vector<int> path;
function<void(int)> backtrack = [&](int start) {
    ans.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(i + 1);
        path.pop_back();
    }
};
backtrack(0);
```

Avoid duplicates (sort first):

```cpp
for (int i = start; i < nums.size(); i++) {
    if (i > start && nums[i] == nums[i - 1]) continue;
    // ...
}
```

---

## 55. Common Return Patterns

```cpp
return {};              // empty vector
return {i, j};          // vector literal
return count == 0;      // boolean directly
if (nums.empty()) return 0;  // early return
```

---

## 56. Answer Variable Initialization

```cpp
int ans = INT_MIN;      // for maximum
int ans = INT_MAX;      // for minimum
long long ans = LLONG_MAX;
int count = 0;
bool found = false;
```

---

## 57. Common Templates

### Two Sum

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

### Merge Intervals

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (auto& cur : intervals) {
        if (ans.empty() || ans.back()[1] < cur[0]) ans.push_back(cur);
        else ans.back()[1] = max(ans.back()[1], cur[1]);
    }
    return ans;
}
```

### Top K Frequent

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    priority_queue<pair<int, int>> pq;
    for (auto& [num, count] : freq) pq.push({count, num});
    vector<int> ans;
    while (k--) { ans.push_back(pq.top().second); pq.pop(); }
    return ans;
}
```

### Grid BFS

```cpp
// See orangesRotting-style problem
queue<pair<int, int>> q;
vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (auto [dr, dc] : dirs) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
        // process cell
    }
}
```

---

## 58. Syntax Pitfalls

| Pitfall | Fix |
|---------|-----|
| `if (x = 5)` | `if (x == 5)` |
| `int x = 5 / 2` (want float) | `double x = 5.0 / 2` |
| `long long x = a * b` (int overflow) | `long long x = 1LL * a * b` |
| `nums[nums.size()]` | `nums[nums.size() - 1]` |
| Reverse loop with `size_t` | `int n = nums.size(); for (int i = n-1; ...)` |
| Mutating container while iterating | Use index loop or collect changes separately |

---

## 59. Cheat Sheet

### Containers

```cpp
vector<int> v;
string s;
unordered_map<int, int> mp;
unordered_set<int> st;
map<int, int> orderedMap;
set<int> orderedSet;
stack<int> stk;
queue<int> q;
deque<int> dq;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
```

### Algorithms

```cpp
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);
lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
count(v.begin(), v.end(), x);
find(v.begin(), v.end(), x);
```

### Loops

```cpp
for (int i = 0; i < n; i++) {}
for (int x : nums) {}
for (auto& [k, v] : mp) {}
```

---

## 60. What to Learn First

**Highest priority for LeetCode:**

1. `vector`, `string`, `unordered_map`, `unordered_set`
2. `sort`, `reverse`, `lower_bound`, `accumulate`
3. `stack`, `queue`, `priority_queue`
4. Recursive DFS with `TreeNode*`
5. BFS with `queue`
6. Custom sort lambdas
7. Prefix sums and sliding windows
8. `long long` overflow prevention
9. Binary search templates
10. `pair`, structured bindings, range loops

**Most valuable modern C++ features for LeetCode:**

- `auto` and `auto [a, b]`
- Lambda functions `[&](...) { ... }`
- Range-based for loops
- `vector` brace initialization
- `unordered_map` / `unordered_set`
- `priority_queue` with `greater<>`
- `function<...>` recursive lambdas
