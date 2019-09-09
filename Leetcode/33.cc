#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		if (!nums.size()) return -1;
        if (nums.size() == 1 && nums[0] != target) return -1; 
        if (nums.size() == 1 && nums[0] == target) return 0;
		int min_l = nums[0];
		int l = 1;
		int r = nums.size() - 1;
		while (l < nums.size() && r < nums.size() && l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] > nums[mid + 1]) break;
			else if (nums[mid] > min_l) l = mid + 1;
			else if (nums[mid] < min_l) r = mid - 1;
		}
		int mid_l = l + (r - l) / 2;
		if (target == nums[mid_l]) return mid_l;
		if (target >= nums[0]) {
			int l = 0;
			int r = mid_l;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < target) l = mid + 1;
				else if (nums[mid] > target) r = mid - 1;
			}
			return -1;
		} 
		if (target <= nums[0]) {
			int l = mid_l + 1;
			if (l >= nums.size()) return -1;
			int r = nums.size() - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < target) l = mid + 1;
				else if (nums[mid] > target) r = mid - 1;
			}
			return -1;
		}
		return -1;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{1,3};
	cout << s.search(nums, 0);
	return 0;
}


