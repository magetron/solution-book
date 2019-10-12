#include<bits/stdc++.h>
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
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> ans(nums.size(), 1);
	   int s = 1;
	   for (int i = nums.size() - 2; i >= 0; i--) {
		   s *= nums[i + 1];
		   ans[i] = s;
	   }
	   s = 1;
	   for (int i = 1; i < nums.size(); i++) {
		   s *= nums[i - 1];
		   ans[i] *= s;
	   }
	   return ans;
    }
};

