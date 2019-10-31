#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) dp.push_back(nums[i]);
            else *it = nums[i]; 
        }
        return dp.size(); 
    }
};
