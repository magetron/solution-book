#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void dfs(vector<int>& nums, int l, vector<vector<int>>& ans) {
		if (l == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int i = l; i < nums.size(); i++) {
			int j = i - 1;
			while (j >= l && nums[i] != nums[j]) j--;
			if (j != l - 1) continue;
			swap(nums[l], nums[i]);
			dfs(nums, l + 1, ans);
			swap(nums[i], nums[l]);
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		dfs(nums, 0, ans);
    	return ans;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums{1,2,1};
	Solution s;
	auto ans = s.permuteUnique(nums);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}
