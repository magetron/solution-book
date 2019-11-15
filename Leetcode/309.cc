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

	inline int max3 (int a, int b, int c) {
		return max(a, max(b, c));
	}

    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
		int buy0 = INT_MIN, buy1 = INT_MIN;
		int sell0 = 0, sell1 = 0;
		int rest0 = 0, rest1 = 1;
		for (int i = 0; i < prices.size(); i++) {
			buy1 = max(rest0 - prices[i], buy0);
			sell1 = max(buy0 + prices[i], sell0);
			rest1 = max3(sell0, buy0, rest0);
			buy0 = buy1, sell0 = sell1, rest0 = rest1;
		}
		//for (int i = 0; i < prices.size(); i++) 
		//	cout << buy[i] << " " << sell[i] << " " << rest[i] << endl;
		return sell0;
	}
};


