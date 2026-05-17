import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from solution import RandomizedSet

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
