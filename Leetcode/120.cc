#include <bits/stdc++.h>

using namespace std;

static int fast_io = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> dp(triangle.back().size());
		for (int i = triangle.size() - 1; i >= 0; i--) 
			for (int j = 0; j <= i; j++) 
				if (i == triangle.size() - 1) dp[j] = triangle[i][j];
				else dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		return dp[0];
    }
};

