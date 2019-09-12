#include <bits/stdc++.h>

using namespace std;

class Solution {
	public :

		void print_map (vector<string>& a) {
			for (auto str : a) cout << str << endl;
		}

		bool check (vector<string>& map, int i, int j, int n) {
			for (int k = 0; k < n; k++) if (map[i][k] == 'Q') return false;
			for (int k = 0; k < n; k++) if (map[k][j] == 'Q') return false;
			int x = i - 1;
			int y = j - 1;
			while (x >= 0 && y >= 0) {
				if (map[x][y] == 'Q') return false;
				x--;
				y--;
			}
			x = i + 1;
			y = j - 1;
			while (x < n && y >= 0) {
				if (map[x][y] == 'Q') return false;
				x++;
				y--;
			}
			x = i - 1;
			y = j + 1;
			while (x >= 0 && y < n) {
				if (map[x][y] == 'Q') return false;
				x--;
				y++;
			}
			x = i + 1;
			y = j + 1;
			while (x < n && y < n) {
				if (map[x][y] == 'Q') return false;
				x++;
				y++;
			}
			return true;
		}
		
		void dfs (vector<string>& map, int j, int n, int& ans) {
			if (j == n) {
				ans++;
				return;
			}
			for (int i = 0; i < n; i++) 
				if (check(map, i, j, n)) {
					map[i][j] = 'Q';
					dfs(map, j + 1, n, ans);
					map[i][j] = '.';
				}
		}

		int totalNQueens (int n) {
			int ans = 0;
			string line(n, '.');
			vector<string> map(n, line);
			dfs(map, 0, n, ans);
			return ans;
		}

};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.totalNQueens(1);
	return 0;
}
