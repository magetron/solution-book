#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
 		sort(nums.begin(), nums.end());
		int min_gap = INT_MAX;
		int min = 0;
		for (int i = 0; i < nums.size() - 2; i++) {
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {
				int res = nums[i] + nums[l] + nums[r];	
				int gap = abs(res - target);
				if (gap < min_gap) {
					min_gap = gap;
					min = nums[i] + nums[l] + nums[r];
				}
				if (res > target) r--;
				else if (res < target) l++;
				else if (res == target) return target;
			}
		}
		return min;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{-1, 2, 1, -4};
	cout << s.threeSumClosest(nums, 1);
	return 0;
}
