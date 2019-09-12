#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		void print(vector<int> a) {
			for (auto i : a) cout << i << " ";
			cout << endl;
		}

		vector<vector<int>> permuteUnique(vector<int>& nums) {
			if (nums.size() == 0) return vector<vector<int>>();
			set<vector<int>> ans{vector<int>()};
			for (int i = 0; i < nums.size(); i++) {
				set<vector<int>> new_ans;
				for (auto per : ans) {
					for (auto it = per.begin(); it != per.end(); it++) {
						vector<int> cpy(per.begin(), it);
						cpy.push_back(nums[i]);
						cpy.insert(cpy.end(), it, per.end());
						new_ans.insert(cpy);
					}
					per.push_back(nums[i]);
					new_ans.insert(per);
				}
				ans = new_ans;
			}
			vector<vector<int>> ret(ans.begin(), ans.end());
			return ret;
		}
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{1,1,2};
	auto ans = s.permuteUnique(nums);
	for (auto as : ans) s.print(as);
	return 0;
}
