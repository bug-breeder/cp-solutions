#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    vector<int> prices1{7, 1, 5, 3, 6, 4};
    vector<int> prices2{7, 6, 4, 3, 1};
    vector<int> prices3{1};
    test(sol.maxProfit(prices1) == 5, "Example 1");
    test(sol.maxProfit(prices2) == 0, "Example 2");
    test(sol.maxProfit(prices3) == 0, "Single price");
    return summary();
}
