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

    int minTotalDistance(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		vector<int> xps;
		vector<int> yps;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (grid[i][j]) {
				xps.push_back(i);
				yps.push_back(j);
			}
		//for (auto x : xps) cout << x << " "; cout << endl;
		//for (auto y : yps) cout << y << " "; cout << endl;
    	sort(yps.begin(), yps.end());
		int x = xps[xps.size() / 2];
		int y = yps[yps.size() / 2];
		int ans = 0;
		for (int i = 0; i < xps.size(); i++) ans += abs(xps[i] - x);
		for (int i = 0; i < yps.size(); i++) ans += abs(yps[i] - y);
		return ans;
	}
};
