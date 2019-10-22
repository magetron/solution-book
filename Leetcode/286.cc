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

	vector<vector<int>> d{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void wallsAndGates(vector<vector<int>>& rooms) {
		int m = rooms.size();
		if (!m) return;
		int n = rooms[0].size();
		if (!n) return;
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (rooms[i][j] == 0) q.push({i, j});
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = p.first + d[i][0];
				int y = p.second + d[i][1];
				if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == INT_MAX) {
					rooms[x][y] = rooms[p.first][p.second] + 1;
					q.push({x, y});
				}
			}
		}
		/*
        for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) cout << rooms[i][j] << " ";
			cout << endl;
		}*/
    }
};

int main () {
	Solution s;
	vector<vector<int>> rooms{{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
	s.wallsAndGates(rooms);
	return 0;
}


