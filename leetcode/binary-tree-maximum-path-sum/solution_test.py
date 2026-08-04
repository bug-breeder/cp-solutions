import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional
from tools.leetcode import test, summary
from solution import Solution

def make_tree(vals):
    if not vals:
        return None
    nodes = [TreeNode(v) if v is not None else None for v in vals]
    for i, node in enumerate(nodes):
        if node:
            left_i, right_i = 2*i+1, 2*i+2
            if left_i < len(nodes): node.left = nodes[left_i]
            if right_i < len(nodes): node.right = nodes[right_i]
    return nodes[0]

test(Solution().maxPathSum(make_tree([1, 2, 3])), 6, "Example 1")
test(Solution().maxPathSum(make_tree([-10, 9, 20, None, None, 15, 7])), 42, "Example 2")
test(Solution().maxPathSum(make_tree([-3])), -3, "Single negative node")

summary()
