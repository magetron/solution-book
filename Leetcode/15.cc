#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3) return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = nums.size() - 1;
			if (nums[i] + nums[l] + nums[l + 1] > 0) break;
			while (l < r) {
				if (l > i + 1 && nums[l] == nums[l - 1]) { l++; continue;}
				if (r < nums.size() - 1 && nums[r] == nums[r + 1]) { r--; continue; }
				if (nums[l] + nums[r] == - nums[i]) {
					//cout << nums[i] << " " << nums[l] << " " << nums[r] << endl;
					ans.push_back({nums[i], nums[l], nums[r]});
					l++;
					r--;
					continue;
				}
				if (nums.at(l) + nums.at(r) > - nums.at(i)) r--;
				else l++;
			}
    	}
		return ans;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{-2,0,0,2,2};
	s.threeSum(nums);
	//cout << s.threeSum(nums) << endl;
	return 0;
}
