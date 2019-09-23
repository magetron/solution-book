#include <bits/stdc++.h>
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
		vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		bool investigate(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited) {
			//cout << "call" << i << " " << j << endl;
			if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
			if (board[i][j] == 'X') return true;
			bool res = true;
			visited[i + 1][j + 1] = true;
			for (int k = 0; k < 4; k++)
				if (!visited[i + dir[k].first + 1][j + dir[k].second + 1])
                    res = investigate(board, i + dir[k].first, j + dir[k].second, visited) && res;
			return res;
		}

		void flip(vector<vector<char>>& board, int i, int j) {
			if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X') return;
			board[i][j] = 'X';
			//for (auto l : board) {
			//	for (auto i : l) cout << i << " ";
			//	cout << endl;
			//}
			//cout << "-----" << endl;
			for (int k = 0; k < 4; k++) flip(board, i + dir[k].first, j + dir[k].second);
		}

		void solve(vector<vector<char>>& board) {
			int m = board.size();
			if (m == 0) return;
			int n = board[0].size();
			if (n == 0) return;
			vector<vector<bool>> visited(m + 2, vector<bool>(n + 2, false));
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++) if (board[i][j] == 'O' && !visited[i + 1][j + 1]) 
                    if (investigate(board, i, j, visited)) flip(board, i, j);
		}
};

int main () {
	Solution s;
	vector<vector<char>>board{{'O','O','O','O','X','X'},
		{'O','O','O','O','O','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','X','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','O','O'}};
	s.solve(board);
	for (auto l : board) {
		for (auto i : l) cout << i << " ";
		cout << endl;
	}
	return 0;
}
