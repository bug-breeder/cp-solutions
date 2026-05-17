#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    test(mf.findMedian() == 1.5, "Median of [1,2]");
    mf.addNum(3);
    test(mf.findMedian() == 2.0, "Median of [1,2,3]");
    return summary();
}
