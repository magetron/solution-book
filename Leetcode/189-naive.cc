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
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return;
        k %= nums.size();
		vector<int> ans(nums.size());
		for (int i = nums.size() - k; i < nums.size(); i++) ans[i - nums.size() + k] = nums[i];
		for (int i = 0; i < nums.size() - k; i++) ans[k + i] = nums[i];
		nums = ans;
	}
};


int main () {
	Solution s;
	vector<int> n{1,2,3,4,5};
	s.rotate(n, 1);
	for (auto i : n) cout << i << " ";
	cout << endl;
	return 0;
}
