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
	vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	void fill(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;
		grid[i][j] = '0';
		for (int k = 0; k < 4; k++) fill(grid, i + d[k][0], j + d[k][1]);
	}

    int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
        if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (grid[i][j] == '1') {
                    ans++;
                    fill(grid, i, j);
                }
		return ans;
    }
};

