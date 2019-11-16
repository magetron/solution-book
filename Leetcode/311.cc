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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		int mA = A.size();
		if (!mA) return {{}};
		int nA = A[0].size();
		if (!nA) return {{}};
		int mB = B.size();
		if (!mB) return {{}};
		int nB = B[0].size();
		if (!nB) return {{}};
		vector<vector<int>> ans(mA, vector<int>(nB, 0));
		for (int i = 0; i < mA; i++)
			for (int j = 0; j < nB; j++) {
				int s = 0;
				for (int k = 0; k < nA; k++) s += A[i][k] * B[k][j];
				ans[i][j] = s;
			}
		return ans;
    }
};
