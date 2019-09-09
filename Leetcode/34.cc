#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<int> searchRange (vector<int>& nums, int target) {
			if (nums.size() == 0) return vector<int>{-1, -1};
			int l = 0;
			int r = nums.size() - 1;
			while (l < r) {
            	//cout << l << " " << r << endl;
				int mid = l + (r - l) / 2;
				if (nums[mid] == target) break;
				if (nums[mid] < target) l = mid + 1;
				else r = mid;
			}
            if (l >= nums.size() || r >= nums.size()) return vector<int>{-1, -1};
            int mid = l + (r - l) / 2;
			if (nums[mid] != target) return vector<int>{-1, -1};
			l = 0;
			r = mid;
			//cout << r << endl;
			int l_mid;
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] < target && nums[mid + 1] == target) break;
				if (nums[mid] < target) l = mid + 1;
				else r = mid;
			}
			if (r == 0) l_mid = 0; else l_mid = l + (r - l) / 2 + 1;
			l = mid + 1;
			if (l >= nums.size() || nums[l] > target) return vector<int>{l_mid, mid};
			r = nums.size() - 1;
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (nums[mid] == target && nums[mid + 1] > target) break;
				if (nums[mid] == target) l = mid + 1;
				else r = mid;
			}
			int r_mid = l + (r - l) / 2;
			return vector<int>{l_mid, r_mid};
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{2, 2};
	vector<int> ans = s.searchRange(nums, 2);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}

