#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    {
        vector<string> g = {"@a"};
        test(Solution{}.shortestPathAllKeys(g) == 1, "One key, adjacent");
    }
    {
        vector<string> g = {"@.a..", "###.#", "b.A.B"};
        test(Solution{}.shortestPathAllKeys(g) == 8, "Example 1");
    }
    return summary();
}
