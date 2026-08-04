"""Shared test helpers for Python LeetCode solutions."""

import sys

_pass = 0
_fail = 0


def test(result, expected, name):
    global _pass, _fail
    ok = result == expected
    print(f"{'PASS' if ok else 'FAIL'}: {name}")
    if not ok:
        print(f"  Expected: {expected!r}")
        print(f"  Got:      {result!r}")
    if ok:
        _pass += 1
    else:
        _fail += 1


def summary() -> None:
    print(f"\n{_pass}/{_pass + _fail} tests passed")
    sys.exit(1 if _fail else 0)
