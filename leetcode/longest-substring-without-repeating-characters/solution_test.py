import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import Solution

sol = Solution()
test(sol.lengthOfLongestSubstring("abcabcbb"), 3, "Example 1")
test(sol.lengthOfLongestSubstring("bbbbb"), 1, "Example 2")
test(sol.lengthOfLongestSubstring("pwwkew"), 3, "Example 3")

summary()
