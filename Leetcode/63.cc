#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (m == 0 || n == 0) return 0;
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
		vector<long> dp(n, 0);
		dp[0] = 1;
		for (int i = 0; i < m; i++) {
            dp[0] = (obstacleGrid[i][0]) ? 0 : dp[0];   
			for (int j = 1; j < n; j++) 
				if (obstacleGrid[i][j]) dp[j] = 0; else dp[j] += dp[j - 1];
        }
		return (int)dp[n - 1];
    }
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> l1{0, 1, 0};
	vector<int> l2{1, 0, 0};
	vector<int> l3{0, 0, 0};
	vector<vector<int>> grid{l1, l2, l3};
	cout << s.uniquePathsWithObstacles(grid) << endl;
	return 0;
}
