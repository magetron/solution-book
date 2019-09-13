#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		vector<int> dp(n, 0);
		dp[0] = grid[0][0];
		for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
		for (int i = 1; i < m; i++) {
			dp[0] += grid[i][0];
			for (int j = 1; j < n; j++) dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
		}
		return dp[n - 1];
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> l1{1, 3, 1};
	vector<int> l2{1, 5, 1};
	vector<int> l3{4, 2, 1};
	vector<vector<int>> grid{l1, l2, l3};
	cout << s.minPathSum(grid) << endl;
	return 0;
}

