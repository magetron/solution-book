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
		if (mb != nA || !mb) return {{}};
		int nB = B[0].size();
		if (!nB) return {{}};
		vector<tuple<int, int, int>> dictA;
		vector<tuple<int, int, int>> dictB;
		for (int i = 0; i < mA; i++)
			for (int j = 0; j < nA; j++) if (A[i][j]) dictA.push_back(make_tuple(i, j, A[i][j]));
		for (int i = 0; i < mB; i++)
			for (int j = 0; j < nB; j++) if (B[i][j]) dictB.push_back(make_tuple(i, j, B[i][j]));
		vector<vector<int>> ans(mA, vector<int>(nB));
		for (auto [iA, jA, vA] : dictA)
			for (auto [iB, jB, vB] : dictB) if (jA == iB) {
				ans[iA][jB] += vA * vB;
			}
		return ans;
	}
}
