# cp-solutions

Competitive programming and LeetCode solutions in C++ and Python.

## Structure

```
leetcode/<problem-name>/
├── solution.cpp        # C++ solution (pure class, no includes)
├── solution.py         # Python solution (class-based)
├── solution_test.cpp   # C++ test harness
└── solution_test.py    # Python test harness

tools/
├── leetcode.h          # Common C++ types + test helpers
└── test.sh             # Unified test runner

learning/               # Language syntax guides
```

## Adding New Solutions

Use `/new-solution <problem-name>` to scaffold all four files for a new problem.

## Running Tests

```bash
# Via Claude skill
/test two-sum
/test two-sum cpp
/test two-sum py

# Directly
bash tools/test.sh two-sum both
```

## C++ Style

- **No includes in solution.cpp** — LeetCode provides them; test harness provides `tools/leetcode.h`
- C++20: structured bindings (`auto [a, b]`), `std::optional`, `.contains()`
- Types used: `vector`, `unordered_map`, `priority_queue`, `stack`, `pair`, `TreeNode*`, `ListNode*`

## C++ Test Pattern

```cpp
#include "tools/leetcode.h"   // all STL + TreeNode/ListNode + test helpers
#include "solution.cpp"        // the Solution class

int main() {
    Solution sol;
    test(sol.METHOD(ARGS) == EXPECTED, "Example 1");
    return summary();          // prints X/N passed, returns 1 if any fail
}
```

## Python Style

- Minimal imports (only what's used)
- Type hints in method signatures
- Class-based (`class Solution:`)

## Python Test Pattern

```python
from solution import Solution
sol = Solution()
test(sol.METHOD(ARGS), EXPECTED, "Example 1")
summary()
```
