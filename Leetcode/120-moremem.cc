#include <bits/stdc++.h>

using namespace std;

static int fast_io = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:

	int helper(int lvl, int pos, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
		if (lvl >= triangle.size()) return 0;
        if (dp[lvl][pos] != INT_MIN) return dp[lvl][pos];
		dp[lvl][pos] = triangle[lvl][pos] + min(helper(lvl + 1, pos, triangle, dp), helper(lvl + 1, pos + 1, triangle, dp));
		return dp[lvl][pos];
	}

    int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), INT_MIN));
        return helper(0, 0, triangle, dp);
    }
};

