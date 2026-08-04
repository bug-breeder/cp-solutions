import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import MedianFinder

mf = MedianFinder()
mf.addNum(1)
mf.addNum(2)
test(mf.findMedian(), 1.5, "Median of [1,2]")
mf.addNum(3)
test(mf.findMedian(), 2.0, "Median of [1,2,3]")

summary()
