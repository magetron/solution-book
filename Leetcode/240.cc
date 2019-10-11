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
		int n = matrix[0].size();
		if (!n) return false;
		int i = m - 1;
		int j = 0;
		while (i >= 0 && j < n) {
			if (target == matrix[i][j]) return true;
			if (target < matrix[i][j]) i--; else j++;
		}
		return false;
	}
};

