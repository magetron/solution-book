#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> rec_sum(vector<int>& nums, int target, int left) {
			vector<vector<int>> ans;
			if (left == 3) {
				for (int i = 0; i < nums.size() - 2; i++) {
					if (target < 0 && nums[i] >= 0) break;
					if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;
					if (i > 0 && nums[i] == nums[i - 1]) continue;
					int l = i + 1;
					int r = nums.size() - 1;
					while (l < r) {
						if (l > i + 1 && nums[l] == nums[l - 1]) { l++; continue; }
						if (r < nums.size() - 1 && nums[r] == nums[r + 1]) { r--; continue; }
						int sum = nums[i] + nums[l] + nums[r];
						if (sum == target) {
							vector<int> sol{nums[i], nums[l], nums[r]};
							ans.push_back(sol);
							l++;
							r--;
						} else if (sum < target) l++;
						else r--;
					}
				}
				return ans;
			}
			for (auto it = nums.begin(); distance(it, nums.end()) >= left; it++) {
				if (target < 0 && *it >= 0) break;
				int min_sum = 0;
				for (int i = 0; i < left; i++) min_sum += *(next(it, i));
				if (min_sum > target) break;
				if (it != nums.begin() && *it == *prev(it)) continue;
				vector<int> new_nums;
				for (auto i = nums.begin(); i != nums.end(); i++) if (i > it) new_nums.push_back(*i);
				vector<vector<int>> sub_ans = rec_sum(new_nums, target - *it, left - 1);
				for (auto i = sub_ans.begin(); i != sub_ans.end(); i++) {
					i -> push_back(*it);
					ans.push_back(*i);
				}
			}
			return ans;
		}

		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			return rec_sum(nums, target, 4);
		}

};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{-1,0,-5,-2,-2,-4,0,1,-2};
	vector<vector<int>> ans = s.fourSum(nums, -9);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		vector<int> sol = *it;
		for (auto i = sol.begin(); i != sol.end(); i++) cout << *i << " ";
		cout << endl;
	}
	return 0;
}

