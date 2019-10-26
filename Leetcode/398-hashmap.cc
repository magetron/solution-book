class Solution {
public:
    
    unordered_map<int, vector<int>> dict;
    
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i]) == dict.end()) dict[nums[i]] = vector<int>(1, i);
            else dict[nums[i]].push_back(i);
        }
        srand(time(NULL));
    }
    
    int pick(int target) {
        auto it = dict.find(target);
        int r = rand() % (*it).second.size();
        return (*it).second[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
