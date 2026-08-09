#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    vector<int> nums1{2, 7, 11, 15};
    vector<int> nums2{3, 2, 4};
    vector<int> nums3{3, 3};
    test(sol.twoSum(nums1, 9) == vector<int>{0, 1}, "Example 1");
    test(sol.twoSum(nums2, 6) == vector<int>{1, 2}, "Example 2");
    test(sol.twoSum(nums3, 6) == vector<int>{0, 1}, "Example 3");
    return summary();
}
