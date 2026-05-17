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
test(sol.calculate("1 + 1"), 2, "Example 1")
test(sol.calculate(" 2-1 + 2 "), 3, "Example 2")
test(sol.calculate("(1+(4+5+2)-3)+(6+8)"), 23, "Example 3")

summary()
