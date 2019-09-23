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
    int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (auto i : nums) {
			ones = (ones ^ i) & ~twos;
			twos = (twos ^ i) & ~ones;
		}
		return ones;
    }
};

