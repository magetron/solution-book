#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
  		int n = mat.size();
		for (int i = 0; i <= n / 2; i++) 
			for (int j = 0; j < n - i * 2 - 1 ; j++) {
				int tmp = mat[i][i + j];
				mat[i][i + j] = mat[n - 1 - i - j][i];
				mat[n - 1 - i - j][i] = mat[n - 1 - i][n - i - 1 - j];
				mat[n - 1 - i][n - i - 1 - j] = mat[i + j][n - 1 - i];
				mat[i + j][n - 1 - i] = tmp;
			}
    }
};
