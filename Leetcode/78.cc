#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ans;
		ans.push_back(vector<int>());
		for (int i = 0; i < nums.size(); i++) { 
			int org_size = ans.size();
    		for (int j = 0; j < org_size; j++) {
				auto cpy = ans[j];
				cpy.push_back(nums[i]);
				ans.push_back(cpy);
			}
		}
		return ans;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> nums{1,2,3};
	auto ans = s.subsets(nums);
	for (auto as : ans) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}
