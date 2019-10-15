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
	
	inline void tss (vector<int>& nums, int i, int target, int& ans) {
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r) {
			if (nums[l] + nums[r] >= target) r--;
			else {
				ans += (r - l);
				l++;
			}
		}
	}

    int threeSumSmaller(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return (nums[0] < target ? 1 : 0);
		sort(nums.begin(), nums.end());
		int ans = 0;
 		for (int i = 0; i < nums.size() - 2; i++) {
			tss(nums, i, target - nums[i], ans);
		}
		return ans;
	}
};


int main () {
	Solution s;
	vector<int> n{-2,0,1,3};
	cout << s.threeSumSmaller(n, 2) << endl;
	return 0;
}

