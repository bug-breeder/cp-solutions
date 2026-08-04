class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;

        int left = 0;
        int longest = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            ++count[s[right]];

            // Shrink the window until s[right] is no longer duplicated.
            while (count[s[right]] > 1) {
                --count[s[left]];
                ++left;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
