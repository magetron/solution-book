class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) dict.insert({nums[i], i});
        for (int i = 0; i < nums.size(); i++) {
            int h = target - nums[i];
            if (dict.find(h) != dict.end() && i != dict[h]) return {i, dict[h]};
        }
        return {};
    }
};