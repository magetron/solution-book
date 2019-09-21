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
	
	vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int m, int n, int pos) {
		if (pos == word.length()) return true;
		if (i < 0 || j < 0 || i >= m || j >= n) return false;
		//cout << pos << " " << board[i][j] << " " << (visited[i][j] ? "true" : "false") << endl;
		if (board[i][j] != word[pos]) return false;
		board[i][j] = '@';
		for (int k = 0; k < 4; k++) if (dfs(board, word, i + dir[k][0], j + dir[k][1], m, n, pos + 1)) return true;
		board[i][j] = word[pos];
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
  		if (word == "") return false;
		char first = word[0];
		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		if (n == 0) return false;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (board[i][j] == first) {
				bool res = dfs(board, word, i, j, m, n, 0);
				if (res) return true;
			}
		return false;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<char>> board{{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
	Solution s;
	cout <<	(s.exist(board, "ABCCCE") ? "true" : "false" ) << endl;
	return 0;
}
