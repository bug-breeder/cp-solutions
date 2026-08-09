import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
from tools.leetcode import test, summary
from solution import LRUCache

cache = LRUCache(2)
cache.put(1, 1)
cache.put(2, 2)
test(cache.get(1), 1, "get(1) == 1")
cache.put(3, 3)  # evicts key 2
test(cache.get(2), -1, "get(2) == -1 (evicted)")
cache.put(4, 4)  # evicts key 1
test(cache.get(1), -1, "get(1) == -1 (evicted)")
test(cache.get(3), 3, "get(3) == 3")
test(cache.get(4), 4, "get(4) == 4")

summary()
