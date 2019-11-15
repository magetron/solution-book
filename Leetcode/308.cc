#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class NumMatrix {
public:
	vector<vector<int>> mat;
	vector<vector<int>> bit;

    NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return;
		int n = matrix[0].size();
		if (!n) return;
		bit = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		mat = vector<vector<int>>(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) update(i, j, matrix[i][j]);
    }

    void update(int row, int col, int val) {
		int diff = val - mat[row][col];
		mat[row][col] = val;
		row++;
		col++;
		for (int i = row; i < bit.size(); i += (i & (-i))) 
			for (int j = col; j < bit[0].size(); j += (j & (-j))) bit[i][j] += diff;	
    }

	inline int sum (int row, int col) {
		int s = 0;
		row++;
		col++;
		for (int i = row; i > 0; i -= (i & (-i)))
			for (int j = col; j > 0; j -= (j & (-j))) s += bit[i][j];
		return s;
	}

    int sumRegion(int row1, int col1, int row2, int col2) {
		return sum(row2, col2) - sum(row2, col1 - 1) - sum(row1 - 1, col2) + sum(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
