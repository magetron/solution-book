#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int l = 0;
	   int r = nums.size();
	   int pos = - 1;
	   while (l < r) {
		   int mid = l + (r - l) / 2;
		   if (nums[mid] == target) {
			   pos = mid;
			   break;
		   }
		   else if (nums[mid] > target) r = mid;
		   else l = mid + 1;
	   }
	   if (pos == -1) return vector<int>{-1, -1};
	   l = 0;
	   r = pos + 1;
	   int l_pos = -1;
	   while (l < r) {
		   int mid = l + (r - l) / 2;
		   if (nums[mid] == target && (mid - 1 < 0 || nums[mid - 1] < target)) {
			   l_pos = mid;
			   break;
		   } 
		   else if (nums[mid] == target) r = mid;
		   else l = mid + 1;
	   }
	   l = pos;
	   r = nums.size();
	   int r_pos = -1;
	   while (l < r) {
		   int mid = l + (r - l) / 2;
		   if (nums[mid] == target && (mid + 1 == nums.size() || nums[mid + 1] > target)) {
			   r_pos = mid;
			   break;
		   }
		   else if (nums[mid] == target) l = mid + 1;
		   else r = mid;
	   }
	   return vector<int>{l_pos, r_pos};
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

