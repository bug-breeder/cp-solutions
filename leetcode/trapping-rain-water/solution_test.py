import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6, "Example 1")
test(sol.trap([4, 2, 0, 3, 2, 5]), 9, "Example 2")
test(sol.trap([]), 0, "Empty input")
test(sol.trap([5, 5, 5, 5]), 0, "Flat surface")

summary()
