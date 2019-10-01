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
	inline int sqr (int n) {
		return n * n;
	}

    int countPrimes(int n) {
		vector<bool> d(n + 1, true);
		for (int i = 2; sqr(i) <= n; i++)
			if (d[i]) 
				for (int j = sqr(i); j <= n; j += i) b[j] = false;
		int ans = 0;
		for (int i = 2; i <= n; i++) if (d[i]) ans++;
		return ans;
    }
};
