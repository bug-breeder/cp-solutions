class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToPos;

        for(int i = 0; i < nums.size(); i++) {
            if (numToPos[target - nums[i]]) {
                return vector<int>{numToPos[target - nums[i]] - 1, i};
            }
            numToPos[nums[i]] = i + 1;
        }
        return {1, 1};
    }
};
