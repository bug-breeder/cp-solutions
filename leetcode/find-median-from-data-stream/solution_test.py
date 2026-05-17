import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from solution import MedianFinder

_pass = _fail = 0

def test(result, expected, name):
    global _pass, _fail
    ok = result == expected
    print(f"{'PASS' if ok else 'FAIL'}: {name}")
    if not ok:
        print(f"  Expected: {expected!r}")
        print(f"  Got:      {result!r}")
    if ok: _pass += 1
    else:  _fail += 1

def summary():
    print(f"\n{_pass}/{_pass + _fail} tests passed")

mf = MedianFinder()
mf.addNum(1)
mf.addNum(2)
test(mf.findMedian(), 1.5, "Median of [1,2]")
mf.addNum(3)
test(mf.findMedian(), 2.0, "Median of [1,2,3]")

summary()
