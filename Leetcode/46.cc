#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

	void print(vector<int> as) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}

	void dfs(vector<int>& nums, int i, vector<vector<int>>& ans) {
		if (i == nums.size() - 1) {
			vector<int> per(1, nums[i]);
			ans.push_back(per);
			return;
		}
		dfs(nums, i + 1, ans);
		int prev_size = ans.size();
		for (int j = 0; j < prev_size; j++) {
			auto cpy_list = ans[j];
			for (auto it = cpy_list.begin(); it != cpy_list.end(); it++) {
				vector<int> per(cpy_list.begin(), it);
				per.push_back(nums[i]);
				per.insert(per.end(), it, cpy_list.end());
				ans.push_back(per);
			}
			ans[j].push_back(nums[i]);
		}
	}
			
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		dfs(nums, 0, ans);
		return ans;
    }
};



int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums{1, 2, 3};
	Solution s;
	auto ans = s.permute(nums);
	for (auto as : ans) s.print(as);
	return 0;
}
