from typing import List
from math import inf

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        limits = sorted(
            [[idx + height, idx] for idx, height in restrictions] + [[1, 1]],
            reverse=True,
        )

        answer = 0
        height = 0

        for building in range(n + 1):
            while limits and limits[-1][1] < building:
                limits.pop()

            cap = limits[-1][0] - building if limits else inf

            height = min(height + 1, cap)
            answer = max(answer, height)

        return answer
