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
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size());
		ans[0] = 1;
		for (int i = 0; i < nums.size() - 1; i++) ans[i + 1] = ans[i] * nums[i];
		int r = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			ans[i] *= r;
			r *= nums[i];
		}
		for (auto i : ans) cout << i << " "; cout << endl;
		return ans;
    }
};

int main () {
	Solution s;
	vector<int> n{1,2,3,4};
	auto ans = s.productExceptSelf(n);
	return 0;
}
