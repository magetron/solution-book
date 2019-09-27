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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m == 0) return 0;
		int n = dungeon[0].size();
		if (n == 0) return 0;
    	vector<int> dp(n, 0);
		int k = - dungeon[m - 1][n - 1] + 1;
		dp[n - 1] = (k > 1 ? k : 1);
		for (int j = n - 2; j >= 0; j--) {
			int k = dp[j + 1] - dungeon[m - 1][j];
			dp[j] = (k > 1 ? k : 1);
		}
		//for (int j = 0; j < n; j++) cout << dp[j] << " "; cout << endl;
		for (int i = m - 2; i >= 0; i--) {
			int k = dp[n - 1] - dungeon[i][n - 1];
			dp[n - 1] = (k > 1 ? k : 1);
			//cout << i << endl;
			//cout << dp[n - 1] << endl;
			for (int j = n - 2 ; j >= 0; j--) {
				int k = min(dp[j + 1], dp[j]) - dungeon[i][j];
				dp[j] = (k > 1 ? k : 1);
			}
			//for (int j = 0; j < n; j++) cout << dp[j] << " "; cout << endl;
		}
		return dp[0];
	}
};

int main () {
	Solution s;
	//vector<int> l1{-2,-3,3};
	//vector<int> l2{-5,-10,1};
	//vector<int> l3{10,30,-5};
	vector<int> l1{2};
	vector<int> l2{1};
	vector<vector<int>> dungeon{l1, l2};
	cout << s.calculateMinimumHP(dungeon) << endl;
	return 0;
}

