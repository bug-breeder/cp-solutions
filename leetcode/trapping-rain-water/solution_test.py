import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
# TODO: add test cases
# test(sol.trap([0,1,0,2,1,0,1,3,2,1,2,1]), 6, "Example 1")

summary()
