#include <bits/stdc++.h>

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
			if (prices.size() == 0) return 0;
			int min_price = INT_MAX;
			int max_gap = INT_MIN;
			for (int i = 0; i < prices.size(); i++) {
				if (prices[i] < min_price) min_price = prices[i];
				if (prices[i] - min_price > max_gap) max_gap = prices[i] - min_price;
			}
			return max_gap;
		}
};
			
