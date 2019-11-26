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

	vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	void bfs (vector<vector<int>>& grid, vector<vector<int>>& distance, vector<vector<bool>>& visited, int i, int j) {
		queue<pair<int, int>> q;
		q.push({i, j});
		visited[i][j] = true;
		int c = 0;
		distance[i][j] += c;
		while (!q.empty()) {
			int s = q.size();
			c++;
			for (int k = 0; k < s; k++) {
				auto p = q.front(); q.pop();
				for (auto d : dir) {
					int x = p.first + d.first;
					int y = p.second + d.second;
					if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0 && !visited[x][y] && distance[x][y] != INT_MAX) {
						q.push({x, y});
						visited[x][y] = true;
						distance[x][y] += c;
					}
				}
			}
		}
		for (int x = 0; x < grid.size(); x++)
			for (int y = 0; y < grid[0].size(); y++) if (grid[x][y] == 0 && visited[x][y] == false) distance[x][y] = INT_MAX;
	}
				
    int shortestDistance(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		vector<vector<int>> distance(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 && distance[i][j] != INT_MAX) {
					vector<vector<bool>> visited(m, vector<bool>(n, false));
					bfs(grid, distance, visited, i, j);
				}
			}
		int ans = INT_MAX;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) cout << distance[i][j] << " ";
			cout << endl;
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (grid[i][j] == 0) ans = min(ans, distance[i][j]);
		return (ans == INT_MAX ? 0 : ans);
    }
};

int main () {
	Solution s;
	vector<vector<int>> grid{{1, 0, 2, 0, 1},
							 {0, 0, 0, 0, 0},
							 {0, 0, 1, 0, 0}};
	cout << s.shortestDistance(grid) << endl;
	return 0;
}

