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
    int maxProduct(vector<int>& nums) {
		vector<int> dpmax(nums.size() + 1, 0);
		vector<int> dpmin(nums.size() + 1, 0);
		dpmax[0] = 1;
		dpmin[0] = 1;
		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			dpmax[i + 1] = max(max(nums[i] * dpmax[i], nums[i]), dpmin[i] * nums[i]);
			dpmin[i + 1] = min(min(nums[i] * dpmin[i], nums[i]), dpmax[i] * nums[i]);
			ans = max(max(ans, dpmax[i + 1]), dpmin[i] * nums[i]);
		}
		return ans;	
    }
};

int main () {
	Solution s;
	vector<int> n{-2,3,-4,-5,-3};
	cout << s.maxProduct(n) << endl;
	return 0;
}
