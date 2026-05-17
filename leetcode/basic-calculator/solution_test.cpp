#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    test(sol.calculate("1 + 1") == 2, "Example 1");
    test(sol.calculate(" 2-1 + 2 ") == 3, "Example 2");
    test(sol.calculate("(1+(4+5+2)-3)+(6+8)") == 23, "Example 3");
    return summary();
}
