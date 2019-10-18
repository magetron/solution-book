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

	inline bool is_square(int n) {
		int rt = (int)sqrt(n);
		return rt * rt == n;
	}

    int numSquares(int n) {
		int cpy = n;
		while (cpy % 4 == 0) cpy /= 4;
		if (cpy % 8 == 7) return 4;
		if (is_square(n)) return 1;
		for (int i = 1; i * i < n; i++)
			if (is_square(n - i * i)) return 2;
		return 3;
    }
};



