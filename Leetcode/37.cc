#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& board) { 
		dfs(board, 0, 0);
	}

	bool next (int&i, int& j) {
		if (i == 8 && j == 8) return true;
		else {
			if (j < 8) j++;
			else if (j == 8) { j = 0; i++; }
			return false;
		}
	}

	bool check (vector<vector<char>>& board, int i, int j, int n) {
		int ia = i / 3 * 3;
		int ja = j / 3 * 3;
		for (int ii = ia; ii < ia + 3; ii++)
			for (int jj = ja; jj < ja + 3; jj++) 
                if (board[ii][jj] != '.' && n == board[ii][jj] - 48) return false;
		for (ia = 0; ia < 9; ia++)
			if (board[ia][j] != '.' && n == board[ia][j] - 48) return false;
		for (ja = 0; ja < 9; ja++)
			if (board[i][ja] != '.' && n == board[i][ja] - 48) return false;
		return true;
	}

	bool dfs (vector<vector<char>>& board, int i, int j) {
		if (board[i][j] != '.') {
			bool res = next(i, j);
			if (res) return true;
            return dfs(board, i, j);
		} else {
			for (int n = 1; n <= 9; n++) {
				bool check_res = check(board, i, j, n);
                //cout << (check_res ? "true" : "false") << endl;
				if (check_res) {
                    //cout << i << " " << j << " " << n << " | ";
					board[i][j] = n + 48;
                    int oi = i;
                    int oj = j;
					bool res = next(i, j);
					if (res) return true;
					else {
						bool dfs_res = dfs(board, i, j);
						if (dfs_res) return true;
                        i = oi; j = oj;
						board[i][j] = '.';
					}
				}
			}
			return false;
		}
	}
};
