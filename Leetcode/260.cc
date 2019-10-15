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
    vector<int> singleNumber(vector<int>& nums) {
		int fxor = 0;
		for (int n : nums) fxor ^= n;
		fxor &= (-fxor);
		vector<int> ans{0, 0};
		for (int n : nums) {
			if (fxor & n) ans[0] ^= n;
			else ans[1] ^= n;
		}
		return ans;
    }
};

