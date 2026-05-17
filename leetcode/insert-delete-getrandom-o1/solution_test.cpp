#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    RandomizedSet rs;
    test(rs.insert(1) == true,  "Insert 1");
    test(rs.remove(2) == false, "Remove 2 (not present)");
    test(rs.insert(2) == true,  "Insert 2");
    int val = rs.getRandom();
    test(val == 1 || val == 2,  "getRandom in {1,2}");
    test(rs.remove(1) == true,  "Remove 1");
    test(rs.insert(2) == false, "Insert 2 again (duplicate)");
    test(rs.getRandom() == 2,   "getRandom = 2 (only element)");
    return summary();
}
