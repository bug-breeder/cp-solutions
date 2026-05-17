class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.result = float("-inf")
        self.dfs(root)
        return self.result

    def dfs(self, node: Optional[TreeNode]):
        if not node:
            return 0
        left_gain = max(self.dfs(node.left), 0)
        right_gain = max(self.dfs(node.right), 0)
        self.result = max(self.result, node.val + left_gain + right_gain)
        return node.val + max(left_gain, right_gain)
