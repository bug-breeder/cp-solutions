import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.search([4, 5, 6, 7, 0, 1, 2], 0), 4, "Example 1")
test(sol.search([4, 5, 6, 7, 0, 1, 2], 3), -1, "Example 2")
test(sol.search([1], 0), -1, "Example 3")

summary()
