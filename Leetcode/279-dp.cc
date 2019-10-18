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
    
    int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int rt = (int)sqrt(i);
			for (int j = 1; j <= rt; j++) dp[i] = min(dp[i], 1 + dp[i - sqr(j)]);
		}
		return dp[n];
    }
};

