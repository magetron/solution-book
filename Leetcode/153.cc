#include <bits/stdc++.h>
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
    int findMin(vector<int>& nums) {
		if (nums.size() <= 4) {
			int ans = INT_MAX;
			for (auto i : nums) ans = min(ans, i);
			return ans;
		}
		int l = 0;
		int r = nums.size();
		int ans = - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			//cout << nums[mid] << " " << mid << " " << nums.size() << endl;
			if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
				ans = mid + 1;
				//cout << "ans = " << ans << endl;
				break;
			} else if (nums[mid] > nums[0]) l = mid + 1;
			else r = mid;
        }
		return (ans == -1 ? nums[0] : nums[ans]);
    }
};

int main () {
	Solution s;
	vector<int> n{2,1};
	cout << s.findMin(n) << endl;
	return 0;
}
