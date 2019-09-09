#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int l = 0;
			int r = nums.size();
			while (l < r) {
				int mid = l + (r - l) / 2;
				//cout << endl;
				//cout << "mid = " << mid << endl;
				if (nums[mid] == target) return mid;
				if (nums[mid] < target && mid + 1 < nums.size() && nums[mid + 1] > target) return mid + 1;
				if (nums[mid] < target) l = mid + 1;
				else r = mid;
			}
			if (l >= nums.size()) return nums.size();
			else return 0;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{1,3,5,6};
	cout << s.searchInsert(nums, 5) << " " << s.searchInsert(nums, 2) << " "
		<< s.searchInsert(nums, 7) << " " << s.searchInsert(nums, 0) << endl;
	return 0;
}

