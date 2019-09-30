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
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
		
		if (k >= prices.size() / 2) {
			int ans = 0;
			for (int i = 1; i < prices.size(); i++) ans += max(prices[i] - prices[i - 1], 0);
			return ans;
		}

		int *res = new int[2 * k];
		for (int i = 0; i < k; i++) {
			res[2 * i] = INT_MIN;
			res[2 * i + 1] = 0;
		}
		for (auto p : prices) {
			for (int i = k - 1; i >= 0; i--) {
				res[2 * i + 1] = max(res[2 * i + 1], res[2 * i] + p); 
				res[2 * i] = max(res[2 * i], (2 * i - 1 >= 0 ? res[2 * i - 1] : 0) - p);
			}
		}
		return res[2 * k - 1];
	}
};


int main () {
	Solution s;
	vector<int> p{2,4,1,2,3,4,3,6};
	cout << s.maxProfit(4, p) << endl;
	return 0;
}
