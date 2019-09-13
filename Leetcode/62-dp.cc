#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			if (m == 0 || n == 0) return 0;
			if (m == 1 || n == 1) return 1;
			vector<int> dp(n, 1);
			for (int i = 1; i < m; i++)
				for (int j = 1; j < n; j++) dp[j] += dp[j - 1];
			return dp[n - 1];
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.uniquePaths(7, 3) << endl;	
	return 0;
}
