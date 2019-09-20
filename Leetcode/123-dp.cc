#include<bits/stdc++.h>

using namespace std;

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if (prices.size() == 0) return 0;
			int k = 2;
			vector<vector<int>> dp(k, vector<int>(prices.size(), 0));
			int minima = INT_MAX;
			for (int i = 0; i < prices.size(); i++) {
				if (prices[i] < minima) minima = prices[i];
				dp[0][i] = (i == 0) ? 0 : max(dp[0][i - 1], prices[i] - minima);
			}
			//for (auto i : dp[0]) cout << i << " ";
			//cout << endl;
			for (int i = 1; i < k; i++) {
				int minima = prices[0];
				dp[i][0] = dp[i - 1][0];
				for (int j = 1; j < prices.size(); j++) {
					minima = min(minima, prices[j] - dp[i - 1][j - 1]);
					dp[i][j] = max(dp[i][j - 1], prices[j] - minima);
				}
			}
			//for (auto i : dp[1]) cout << i << " ";
			//cout << endl;
			return dp[k - 1][prices.size() - 1];
		}
};

int main () {
	vector<int> prices{8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}
