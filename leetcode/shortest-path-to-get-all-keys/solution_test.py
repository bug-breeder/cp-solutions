import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from typing import List
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.shortestPathAllKeys(["@a"]), 1, "One key, adjacent")
test(sol.shortestPathAllKeys(["@.a..", "###.#", "b.A.B"]), 8, "Example 1")

summary()
