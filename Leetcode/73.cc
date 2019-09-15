#include <bits/stdc++.h>
#define VAL -12345678
using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			
			bool zRow = false;
			bool zCol = false;

			if (!matrix[0][0]) {
				zRow = true;
				zCol = true;
			}

			for (int i = 0 ; i < m; i++) if (matrix[i][0] == 0) {
				matrix[i][0] = VAL;
				zCol = true;
				break;
			}

			for (int j = 0; j < n; j++) if (matrix[0][j] == 0) {
				matrix[0][j] = VAL;
				zRow = true;
				break;
			}

			for (int i = 0; i < m; i++) 
				for (int j = 0; j < n; j++) if (matrix[i][j] == 0) {
					matrix[i][0] = VAL;
					matrix[0][j] = VAL;
				}	

			for (int i = 1; i < m; i++) if (matrix[i][0] == VAL) for (int j = 0; j < n; j++) matrix[i][j] = 0;
			for (int j = 1; j < n; j++) if (matrix[0][j] == VAL) for (int i = 0; i < m; i++) matrix[i][j] = 0;	
			/*	
			for (auto as : matrix) {
				for (auto i : as) cout << i << " ";
				cout << endl;
			}
			cout << "------" << endl;
			*/
			if (zCol) for (int i = 0; i < m; i++) matrix[i][0] = 0;
			if (zRow) for (int j = 0; j < n; j++) matrix[0][j] = 0;



		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> mat{{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	Solution s;
	s.setZeroes(mat);
	for (auto as : mat) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}

