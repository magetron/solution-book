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
		int count = 0;
		while (n > 0) {
			n -= (n & (-n));
			count++;
		}
		return count;
    }
};
