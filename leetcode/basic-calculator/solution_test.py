import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.calculate("1 + 1"), 2, "Example 1")
test(sol.calculate(" 2-1 + 2 "), 3, "Example 2")
test(sol.calculate("(1+(4+5+2)-3)+(6+8)"), 23, "Example 3")

summary()
