#include <bits/stdc++.h>
#pragma GCC optimise ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		sort(nums.begin(), nums.end());
		int ans = 0;
		for (int i = 0; i < nums.size() - 1; i++) 
			ans = max(ans, nums[i + 1] - nums[i]);
		return ans;
    }
};
