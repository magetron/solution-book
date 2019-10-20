#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
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
		int diff = 0;
		for (int n : nums) diff ^= n;
		diff &= -diff;
		int a = 0, b = 0;
		for (int n : nums) if (n & diff) a ^= n; else b ^= n;
		return {a, b};
    }
};


