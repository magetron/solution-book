#include <bits/stdc++.h>
#pragma GCC optimze ("Ofast")

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
		int i = nums[0];
		for (int j = 1; j < nums.size(); j++) i ^= nums[j];
		return i;
    }
};
