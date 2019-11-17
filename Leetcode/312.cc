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
    int maxCoins(vector<int>& nums) {
		if (!nums.size()) return 0;
		nums.push_back(1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for (int len = 1; len < nums.size(); len++)
			for (int l = 0; l < nums.size() - len; l++) {
				int r = l + len - 1;
				int max_c = 0;
				for (int last = l; last <= r; last++) {
					int c = (last > 0 ? dp[l][last - 1] : 0)+ dp[last + 1][r] + nums[last] * (l > 0 ? nums[l - 1] : 1) * nums[r + 1];
					max_c = max(c, max_c);
				}
				dp[l][r] = max_c;
			}
		return dp[0][nums.size() - 2];
    }
};

