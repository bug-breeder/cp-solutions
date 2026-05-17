class Solution {
    int ans = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        ans = max(ans, left + right + node->val);
        return max(left, right) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
