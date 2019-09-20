#include<bits/stdc++.h>

using namespace std;

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int i = 0;
			int ans = 0;
			while (i < prices.size()) {
				int j = i + 1;
				while (j < prices.size() && prices[j] > prices[j - 1]) j++;
				j--;
				ans += prices[j] - prices[i];
				i = j + 1;
			}
			return ans;
		}
};
