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
    int hammingWeight(uint32_t n) {
		bitset<32> bs(n);
		int ans = 0;
		for (int i = 0; i < 32; i++) ans += (b[i] ? 1 : 0);
		return ans;
    }
};
