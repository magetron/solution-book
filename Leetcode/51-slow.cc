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
		
		void dfs (vector<string>& map, int i, int j, int count, int n, vector<vector<string>>& ans) {
			//cout << i << " " << j << endl;
			if (i == n) {
				if (count == n) ans.push_back(map);
				return;
			}
			if (j == n) {
				dfs(map, i + 1, 0, count, n, ans);
				return;
			}
			if (check(map, i, j, n)) {
				map[i][j] = 'Q';
				dfs(map, i, j + 1, count + 1, n, ans);
				map[i][j] = '.';
				dfs(map, i, j + 1, count, n, ans);
			} else dfs(map, i, j + 1, count, n, ans);
		}

		vector<vector<string>> solveNQueens (int n) {
			vector<vector<string>> ans;
			string line(n, '.');
			vector<string> map(n, line);
			dfs(map, 0, 0, 0, n, ans);
			return ans;
		}

};
