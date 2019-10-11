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

	inline bool bs(vector<int>& a, int t) {
		int l = 0;
		int r = a.size();
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (a[mid] == t) return true;
			else if (a[mid] < t && mid < a.size() - 1 && a[mid + 1] > t) return false;
			else if (a[mid] > t && mid > 0 && a[mid - 1] < t) return false;
			if (a[mid] > t) r = mid; else l = mid + 1;
		}
		return false;
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (!m) return false;
		int n = matrix[0].size();
		if (!n) return false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] > target) return false;
			if (bs(matrix[i], target)) return true;
		}
		return false;	
    }
};

