class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count: dict[str, int] = {}

        left = 0
        longest = 0

        for right, ch in enumerate(s):
            count[ch] = count.get(ch, 0) + 1

            while count[ch] > 1:
                count[s[left]] -= 1
                left += 1

            longest = max(longest, right - left + 1)

        return longest
