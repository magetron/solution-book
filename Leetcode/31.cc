#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int line;
		int cur_max = INT_MIN;
		auto it = nums.rbegin();
		for (; it != nums.rend(); it++) 
			if (*it >= cur_max) cur_max = *it;
			else {
				line = nums.size() - (it - nums.rbegin());
				break;
			}
		if (it == nums.rend()) {
			sort(nums.begin(), nums.end());
			return;
		} else {
			int val = nums[line - 1];
			int rep = INT_MAX;
			int rep_pos;
			for (int i = line; i < nums.size(); i++) if (nums[i] > val && nums[i] < rep) {
				rep = nums[i];
				rep_pos = i;
			}
			swap(nums[line - 1], nums[rep_pos]);
			sort(nums.begin() + line, nums.end());
		}
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{4,2,4,4,3};
	s.nextPermutation(nums);
	for (auto num : nums) cout << num << " ";
	cout << endl;
	return 0;
}
