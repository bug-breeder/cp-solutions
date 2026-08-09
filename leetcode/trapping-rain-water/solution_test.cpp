#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    vector<int> h1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> h2{4, 2, 0, 3, 2, 5};
    test(sol.trap(h1) == 6, "Example 1");
    test(sol.trap(h2) == 9, "Example 2");
    return summary();
}
