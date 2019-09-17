#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans(1, vector<int>());
		int i = 0;
		while (i < nums.size()) {
			int j = i + 1;
			while (j < nums.size() && nums[j] == nums[i]) j++;
			int count = j - i;
			int org_size = ans.size();
			for (int j = 0; j < org_size; j++)
				for (int k = 1; k <= count; k++) {
					auto cpy = ans[j];
					for (int kk = 0; kk < k; kk++) cpy.push_back(nums[i]);
					ans.push_back(cpy);
				}
			i += count;
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> nums{1,2,2};
	auto ans = s.subsetsWithDup(nums);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}

