import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from solution import Solution

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

sol = Solution()
test(sol.maxBuilding(5, [[2,1],[4,1]]), 2, "Example 1")
test(sol.maxBuilding(6, []), 5, "Example 2 - no restrictions")
test(sol.maxBuilding(10, [[5,3],[2,5],[7,4],[10,3]]), 5, "Example 3")

summary()
