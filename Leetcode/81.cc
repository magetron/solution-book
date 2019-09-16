#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int pivot = -1;
		for (int i = 0; i < nums.size() - 1; i++) if (nums[i] > nums[i + 1]) { pivot = i; break; }
		if (pivot == -1) {
			int l = 0;
			int r = nums.size();
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) return true;
				else if (nums[mid] > target) r = mid;
				else l = mid + 1;
			}
			return false;
		} else {
			int l = 0;
			int r = pivot + 1;
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) return true;
				else if (nums[mid] > target) r = mid;
				else l = mid + 1;
			}
			l = pivot + 1;
			r = nums.size();
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) return true;
				else if (nums[mid] > target) r = mid;
				else l = mid + 1;
			}
			return false;
    	}
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> nums{2,99,100,2,2,2};
	Solution s;
	cout << (s.search(nums, 99) ? "true" : "false") << endl;
	return 0;
}
