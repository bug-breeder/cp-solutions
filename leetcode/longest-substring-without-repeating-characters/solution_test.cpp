#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    test(sol.lengthOfLongestSubstring("abcabcbb") == 3, "Example 1");
    test(sol.lengthOfLongestSubstring("bbbbb") == 1, "Example 2");
    test(sol.lengthOfLongestSubstring("pwwkew") == 3, "Example 3");
    return summary();
}
