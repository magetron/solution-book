#include <bits/stdc++.h>

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
		int hold1 = 0, release1 = 0, hold2 = 0, release2 = 0;
		for (auto price : prices) {
			release2 = max(release2, price + hold2);
			hold2 = max(hold2, release1 - price);
			release1 = max(release1, price + hold1);
			hold1 = max(hold1, hold1 - price);
		}
		return release2;
    }
};
