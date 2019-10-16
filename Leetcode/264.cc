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

	inline int min3 (int a, int b, int c) {
 		return min(min(a, b), c);
	}

    int nthUglyNumber(int n) {
		vector<int> dict(1690);
		int i2 = 0, i3 = 0, i5 = 0;
		dict[0] = 1;
		for (int i = 1; i < n; i++) {
			dict[i] = min3(dict[i2] << 1, dict[i3] * 3, dict[i5] * 5);
			if (dict[i] == dict[i2] << 1) i2++;
			if (dict[i] == dict[i3] * 3) i3++;
			if (dict[i] == dict[i5] * 5) i5++;
		}
		return dict[n - 1];
    }
};

