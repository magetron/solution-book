#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum = n * (1 + n) / 2;
		for (int i : nums) sum -= i;
		return sum;
    }
};
