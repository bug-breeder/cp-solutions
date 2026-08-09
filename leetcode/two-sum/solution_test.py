import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.twoSum([2, 7, 11, 15], 9), [0, 1], "Example 1")
test(sol.twoSum([3, 2, 4], 6), [1, 2], "Example 2")
test(sol.twoSum([3, 3], 6), [0, 1], "Example 3")

summary()
