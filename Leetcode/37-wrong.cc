#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		vector<bool> table;
		int options;

		Node (): table(vector<bool>(10, true)), options(9) { }

		void inValidate (int n) {
			if (n >= 10 || n <= 0) return;
			table[n] = false;
			options--;
		}

		int check () {
			if (options == 1) {
				for (int i = 1; i <= 9; i++) if (table[i]) return i;
				return -1;
			} else return -1;
		}
};

class Solution {
public:
	void c_square(vector<vector<char>>& board, vector<vector<Node>>& dict) {
		for (int i = 0; i <= 6; i += 3)
			for (int j = 0; j <= 6; j += 3) {
				vector<bool> table(10, false);
				for (int m = i; m < i + 3; m++)
					for (int n = j; n < j + 3; n++) if (board[m][n] != '.') table[board[m][n] - 48] = true;
				for (int m = i; m < i + 3; m++)
					for (int n = j; n < j + 3; n++) 
						for (int k = 1; k <= 9; k++) if (board[m][n] == '.' && table[k]) dict[m][n].inValidate(k);
			}
	}

	void c_row(vector<vector<char>>& board, vector<vector<Node>>& dict) {
		for (int i = 0; i < 9; i++) {
			vector<bool> table(10, false);
			for (int j = 0; j < 9; j++) if (board[i][j] != '.') table[board[i][j] - 48] = true;
			for (int j = 0; j < 9; j++) 
				for (int k = 1; k <= 9; k++) if (board[i][j] == '.' && table[k]) dict[i][j].inValidate(k);
		}
	}

	void c_col(vector<vector<char>>& board, vector<vector<Node>>& dict) {
		for (int i = 0; i < 9; i++) {
			vector<bool> table(10, false);
			for (int j = 0; j < 9; j++) if (board[j][i] != '.') table[board[j][i] - 48] = true;
			for (int j = 0; j < 9; j++) 
				for (int k = 1; k <= 9; k++) if (board[j][i] == '.' && table[k]) dict[j][i].inValidate(k);
		}
	}

	void scan(vector<vector<char>>& board, vector<vector<Node>>& dict, int& unsolved) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				int res = dict[i][j].check();
				if (res != -1) {
					board[i][j] = res;
					unsolved--;
				}
			}
	}


    void solveSudoku(vector<vector<char>>& board) {
    	vector<vector<Node>> dict(9, vector<Node>(9, Node()));
		int unsolved = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) if (board[i][j] == '.') unsolved++;
		while (unsolved > 0) {
			c_square(board, dict);
			c_row(board, dict);
			c_col(board, dict);
			scan(board, dict, unsolved);
		}
    }
};

int main () {

	return 0;
}
