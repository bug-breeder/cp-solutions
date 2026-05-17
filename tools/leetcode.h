#pragma once
#include <bits/stdc++.h>
using namespace std;

// ─── Common LeetCode Types ────────────────────────────────────────────────────

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

// ─── Builders ─────────────────────────────────────────────────────────────────

// Sentinel for null nodes: use _ or nullopt
// Example: makeTree({1, 2, 3, _, _, 4, 5})
const optional<int> _ = nullopt;

inline TreeNode* makeTree(vector<optional<int>> vals) {
    if (vals.empty() || !vals[0]) return nullptr;
    auto* root = new TreeNode(*vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < vals.size()) {
        auto* node = q.front(); q.pop();
        if (i < vals.size() && vals[i]) { node->left  = new TreeNode(*vals[i]); q.push(node->left);  } i++;
        if (i < vals.size() && vals[i]) { node->right = new TreeNode(*vals[i]); q.push(node->right); } i++;
    }
    return root;
}

inline ListNode* makeList(vector<int> vals) {
    ListNode dummy;
    auto* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

// ─── Equality ─────────────────────────────────────────────────────────────────

inline bool treeEq(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b || a->val != b->val) return false;
    return treeEq(a->left, b->left) && treeEq(a->right, b->right);
}

inline bool listEq(ListNode* a, ListNode* b) {
    while (a && b) { if (a->val != b->val) return false; a = a->next; b = b->next; }
    return !a && !b;
}

// ─── Test Helpers ─────────────────────────────────────────────────────────────

static int _pass = 0, _fail = 0;

inline void test(bool ok, const string& name) {
    cout << (ok ? "PASS" : "FAIL") << ": " << name << "\n";
    ok ? _pass++ : _fail++;
}

inline int summary() {
    cout << "\n" << _pass << "/" << (_pass + _fail) << " tests passed\n";
    return _fail > 0 ? 1 : 0;
}
