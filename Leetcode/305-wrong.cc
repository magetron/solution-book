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
	vector<pair<int, int>> dir{{0,1},{0,-1},{-1,0},{-1,-1}};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		if (!m || !n) return {};
		int ic = 0;
		vector<int> ans;
		vector<vector<bool>> mp(m, vector<bool>(n, false));
		for (auto pos : positions) {
			mp[pos[0]][pos[1]] = true;
			bool allwater = true;
			for (auto d : dir) {
				int x = pos[0] + d.first;
				int y = pos[1] + d.second;
				if (x >= 0 && x < m && y >= 0 && y < n && mp[x][y]) {
					allwater = false;
					break;
				}
			}
			if (allwater) {
				ic++;
				ans.push_back(ic);
			} else ans.push_back(ic);
		}
		return ans;
    }
};
