#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) return 0;
    	int l = 0;
		int r = nums.size();
		while (l < r) {
			int mid = l + (r - l) / 2;
			//cout << mid << " " << nums[mid] << endl;
			if (mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
			else if ((mid == 0 && nums[1] < nums[0]) || (mid == nums.size() - 1 && nums[mid - 1] < nums[mid])) return mid;
			else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) l = mid + 1;
			else r = mid;
		}
		return -1;
    }
};

int main () {
	Solution s;
	vector<int> n{2,1};
	cout << s.findPeakElement(n) << endl;
	return 0;
}

