class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto i : nums) ans = min(i, ans);
        return ans;
    }
};
