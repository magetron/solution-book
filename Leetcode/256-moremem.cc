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

    int minCost(vector<vector<int>>& costs) {
		int n = costs.size();
		if (!n) return 0;
		vector<vector<int>> dp(n, vector<int>(3));
		dp[0][0] = costs[0][0];
		dp[0][1] = costs[0][1];
		dp[0][2] = costs[0][2];
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1] + costs[i][0], dp[i - 1][2] + costs[i][0]);
			dp[i][1] = min(dp[i - 1][0] + costs[i][1], dp[i - 1][2] + costs[i][1]);
			dp[i][2] = min(dp[i - 1][0] + costs[i][2], dp[i - 1][1] + costs[i][2]);
		}
		return *min_element(dp.back().begin(), dp.back().end());		
    }
};
