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

	vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (!m) return;
		int n = board[0].size();
		if (!n) return;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int nc = 0;
				for (int k = 0; k < 8; k++) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) nc++;
				}
				if (board[i][j] == 1) {
					if (nc < 2) board[i][j] = 2;
					else if (nc > 3) board[i][j] = 2;
				} else {
					if (nc == 3) board[i][j] = 3;
				}
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (board[i][j] == 2) board[i][j] = 0; else if (board[i][j] == 3) board[i][j] = 1;
    }
};

