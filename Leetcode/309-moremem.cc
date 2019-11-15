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
		vector<int> buy(prices.size(), INT_MIN);
		vector<int> sell(prices.size(), 0);
		vector<int> rest(prices.size(), 0);
		for (int i = 0; i < prices.size(); i++) {
			buy[i] = max((i > 0 ? rest[i - 1] : 0) - prices[i], i > 0 ? buy[i - 1] : INT_MIN);
			sell[i] = max((i > 0 ? buy[i - 1] : INT_MIN) + prices[i], i > 0 ? sell[i - 1] : 0);
			rest[i] = max3(i > 0 ? sell[i - 1] : 0, i > 0 ? buy[i - 1] : INT_MIN, i > 0 ? rest[i - 1] : 0);
		}
		//for (int i = 0; i < prices.size(); i++) 
		//	cout << buy[i] << " " << sell[i] << " " << rest[i] << endl;
		return sell.back();
	}
};

