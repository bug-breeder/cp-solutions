#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    // Create a fresh Solution per call — ans is a class member that persists.
    test(Solution{}.maxPathSum(makeTree({1, 2, 3})) == 6, "Example 1");
    test(Solution{}.maxPathSum(makeTree({-10, 9, 20, _, _, 15, 7})) == 42, "Example 2");
    test(Solution{}.maxPathSum(makeTree({-3})) == -3, "Single negative node");
    return summary();
}
