---
name: test
description: Run tests for a LeetCode problem. Usage: /test <problem-name> [cpp|py|both]. Defaults to both languages. Example: /test two-sum cpp
---

Extract the problem name and optional language (cpp / py / both, default: both) from the user's message.

Run: `bash tools/test.sh <problem-name> <lang>`

Show the full output. Then:

- If all tests pass → congratulate briefly.
- If any test fails → look at the solution file and the failing test case, and offer a specific debugging suggestion or fix.
- If test files are missing → suggest `/new-solution <name>` to scaffold them.
- If compilation fails (C++) → show the compiler error and help fix it.
