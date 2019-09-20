#include <bits/stdc++.h>

using namespace std;

static int fast_io = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; } ();

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			vector<int> max_price(prices.size());
			int m = INT_MIN;
			for (int i = prices.size() - 1; i >= 0; i--) {
				if (prices[i] > m) m = prices[i];
				max_price[i] = m;
			}
			int m_gap = 0;
			for (int i = 0; i < prices.size(); i++) {
				int gap = max_price[i] - prices[i];
				if (gap > m_gap) m_gap = gap;
			}
			return m_gap;
		}
};
