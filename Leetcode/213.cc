#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int a = nums[0];
        int b = max(nums[1], nums[0]);
        int ans = 0;
		for (int i = 2; i < nums.size() - 1; i++) {           
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp;
        }
        if (nums.size() <= 2) return b;
        ans = b;

		a = nums[1];
        b = max(nums[1], nums[2]);
		for (int i = 3; i < nums.size(); i++) {           
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp;
        }
        ans = max(ans, b);
		return ans;
    }
};

