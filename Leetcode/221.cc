#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size();
		if (!n) return 0;
		vector<int> dp(n, 0);
		int prev = 0;
        int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int tmp = dp[j];
				if (matrix[i][j] == '0') dp[j] = 0;
				else dp[j] = min(min(dp[j], j > 0 ? dp[j - 1] : 0) , prev) + 1;
				ans = max(ans, dp[j]);
                prev = tmp;
			}
		return ans * ans;
	}
};


