class Solution {
public:
    pair<int, int> calc(TreeNode* root) {
        // returns {maxPathSum in subtree, maxPathSum as single arm ending at root}
        if (!root) return {INT_MIN, 0};
        auto [leftPath, leftArm] = calc(root->left);
        auto [rightPath, rightArm] = calc(root->right);

        int arm = root->val + max(0, max(leftArm, rightArm));
        int path = max({root->val + max(0, leftArm) + max(0, rightArm), leftPath, rightPath});

        return {path, arm};
    }

    int maxPathSum(TreeNode* root) {
        return calc(root).first;
    }
};
