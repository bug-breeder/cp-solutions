#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    {
        vector<int> p = {1, 2, 3}, c = {0, 1, 1};
        test(sol.findMaximizedCapital(2, 0, p, c) == 4, "Example 1");
    }
    {
        vector<int> p = {1, 2, 3}, c = {0, 1, 2};
        test(sol.findMaximizedCapital(3, 0, p, c) == 6, "Example 2");
    }
    return summary();
}
