#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    test(sol.search(nums1, 0) == 4, "Example 1");

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    test(sol.search(nums2, 3) == -1, "Example 2");

    vector<int> nums3 = {1};
    test(sol.search(nums3, 0) == -1, "Example 3");

    return summary();
}
