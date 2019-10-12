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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
 		int m = matrix.size();
		if (!m) return false;
        m--;
		int n = 0;
        while (m >= 0 && n < matrix[0].size()) {
			if (matrix[m][n] == target) return true;
			else if (matrix[m][n] > target) m--; else n++;
		}
		return false;
    }
};

