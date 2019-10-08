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
		vector<vector<int>>dp (m, vector<int>(n, 0));
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == '0') dp[i][j] = 0;
				else {
					dp[i][j] = min(min(i > 0 ? dp[i - 1][j] : 0, i > 0 && j > 0 ? dp[i - 1][j - 1] : 0), j > 0 ? dp[i][j - 1] : 0) + 1;
					ans = max(ans, dp[i][j]);
				}
		return ans * ans;
    }
};

