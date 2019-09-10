#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<bool> std_table;

		Solution () {
			std_table = vector<bool>(10, false);
		}

		bool c_square(vector<vector<char>>& board, int x, int y) {
			vector<bool> table(std_table);
			for (int i = x; i < x + 3; i++)
				for (int j = y; j < y + 3; j++)
					if (board[i][j] != '.') {
						if (board[i][j] == 48) return false;
						else if (table[board[i][j] - 48]) return false;
						else table[board[i][j] - 48] = true;
					}
			return true;
		}

		bool c_row(vector<vector<char>>& board, int row) {
			vector<bool> table(std_table);
			for (int i = 0; i < 9; i++)
				if (board[row][i] != '.') {
					if (table[board[row][i] - 48]) return false;
					else table[board[row][i] - 48] = true;
				}
			return true;
		}

		bool c_col(vector<vector<char>>& board, int col) {
			vector<bool> table(std_table);
			for (int i = 0; i < 9; i++)
				if (board[i][col] != '.') {
					if (table[board[i][col] - 48]) return false;
					else table[board[i][col] - 48] = true;
				}
			return true;
		}

        void print(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
                cout << endl;
            }
        }

		bool isValidSudoku(vector<vector<char>>& board) {
            //print(board);
			bool isValid = true;
			for (int i = 0; i <= 6; i += 3)
				for (int j = 0; j <= 6; j += 3) {
					isValid &= c_square(board, i, j);
					if (!isValid) return false;
				}
			for (int i = 0; i < 9; i++) {
				isValid &= c_row(board, i);
				if (!isValid) return false;
			}
			for (int i = 0; i < 9; i++) {
				isValid &= c_col(board, i);
				if (!isValid) return false;
			}
			return true;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}

