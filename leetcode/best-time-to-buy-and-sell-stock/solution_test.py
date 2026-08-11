import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.maxProfit([7, 1, 5, 3, 6, 4]), 5, "Example 1")
test(sol.maxProfit([7, 6, 4, 3, 1]), 0, "Example 2")
test(sol.maxProfit([1]), 0, "Single price")

summary()
