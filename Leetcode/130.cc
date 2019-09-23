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

		void mark(vector<vector<char>>& board, int i, int j) {
			if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '*') return;
			board[i][j] = '*';
			for (int k = 0; k < 4; k++) mark(board, i + dir[k].first, j + dir[k].second);
		}

		void solve(vector<vector<char>>& board) {
			int m = board.size();
			if (m == 0) return;
			int n = board[0].size();
			if (n == 0) return;
			for (int i = 0; i < m; i++) {
				if (board[i][0] == 'O') mark(board, i, 0);
				if (board[i][n - 1] == 'O') mark(board, i, n - 1);
			}
			for (int j = 0; j < n; j++) {
				if (board[0][j] == 'O') mark(board, 0, j);
				if (board[m - 1][j] == 'O') mark(board, m - 1, j);
			}
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++) 
					if (board[i][j] == 'O') board[i][j] = 'X';
					else if (board[i][j] == '*') board[i][j] = 'O';
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
