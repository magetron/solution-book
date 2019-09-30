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
        int i = 0, j = 0;
		for (auto n : nums) {
			i = i ^ (n & ~j);
			j = j ^ (n & ~i);
		}
		return i;
    }
};

