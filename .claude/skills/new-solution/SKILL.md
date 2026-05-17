---
name: new-solution
description: Scaffold a new LeetCode problem with C++ and Python solution stubs plus test harnesses. Usage: /new-solution <problem-name-in-kebab-case>. Example: /new-solution two-sum
---

Extract the problem name (kebab-case slug) from the user's message.

Create these four files under `leetcode/<name>/`:

**solution.cpp** — pure class stub (no includes; LeetCode provides them):
```cpp
class Solution {
public:
    // TODO: implement
};
```

**solution.py** — class stub:
```python
class Solution:
    def solve(self) -> None:
        pass  # TODO: implement
```

**solution_test.cpp** — C++ test harness:
```cpp
#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    Solution sol;
    // TODO: add test cases
    // test(sol.METHOD(ARGS) == EXPECTED, "Example 1");
    return summary();
}
```

**solution_test.py** — Python test harness (self-contained):
```python
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
# TODO: add test cases
# test(sol.METHOD(ARGS), EXPECTED, "Example 1")

summary()
```

After creating all files, tell the user:
- Fill in the method signature in solution.cpp and solution.py
- Add test cases to both test files
- Run `/test <name>` when ready
