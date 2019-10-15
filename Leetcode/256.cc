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

    int minCost(vector<vector<int>>& costs) {
		int n = costs.size();
		if (!n) return 0;
		vector<vector<int>> dp(n, vector<int>(3));
		int ro = costs[0][0];
		int bo = costs[0][1];
		int go = costs[0][2];
		int r = 0, g = 0, b = 0;
		for (int i = 1; i < n; i++) {
			r = min(bo + costs[i][0], go + costs[i][0]);
			b = min(ro + costs[i][1], go + costs[i][1]);
			g = min(ro + costs[i][2], bo + costs[i][2]);
			ro = r; bo = b; go = g;
		}
    	return min(min(r, b), g);
	}
};
