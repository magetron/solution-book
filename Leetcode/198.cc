class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int a = nums[0];
        int b = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {           
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp;
        }
        return b;
    }
};
