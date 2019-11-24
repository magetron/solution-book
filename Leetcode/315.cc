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

	void ms (int l, int r, vector<int>& nums, vector<int>& ans, vector<int>& index) {
		if (r - l == 1) return;

		int mid = l + (r - l) / 2;
		ms(l, mid, nums, ans, index);
		ms(mid, r, nums, ans, index);

		vector<int> merged; merged.reserve(r - l);
		int i = l, j = mid;
		int cnt = 0; 
		while (i < mid || j < r) {
			if (j == r || (i < mid && nums[index[i]] <= nums[index[j]])) {
				merged.emplace_back(index[i]);
				ans[index[i]] += cnt;
				i++;
			} else {
				merged.emplace_back(index[j]);
				cnt++;
				j++;
			}
		}
		move(merged.begin(), merged.end(), index.begin() + l);
	}

    vector<int> countSmaller(vector<int>& nums) {
		if (!nums.size()) return {};
  		vector<int> ans(nums.size(), 0);
		vector<int> index(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) index[i] = i;
		ms(0, nums.size(), nums, ans, index);
		return ans;
    }
};
