import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import RandomizedSet

rs = RandomizedSet()
test(rs.insert(1), True,  "Insert 1")
test(rs.remove(2), False, "Remove 2 (not present)")
test(rs.insert(2), True,  "Insert 2")
val = rs.getRandom()
test(val in (1, 2), True, "getRandom in {1,2}")
test(rs.remove(1), True,  "Remove 1")
test(rs.insert(2), False, "Insert 2 again (duplicate)")
test(rs.getRandom(), 2,   "getRandom = 2 (only element)")

summary()
