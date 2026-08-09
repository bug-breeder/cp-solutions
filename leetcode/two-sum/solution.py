class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        num_to_pos = {}

        for i, num in enumerate(nums):
            if target - num in num_to_pos:
                return [num_to_pos[target - num], i]
            num_to_pos[num] = i

        return []
