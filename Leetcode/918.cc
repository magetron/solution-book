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
    
	inline int dp(vector<int>& a, int l, int r, int s) {
		int suff_m = s * a[l];
		int m = s * a[l];
		for (int i = l + 1; i <= r; i++) {
			suff_m = max(suff_m + s * a[i], s * a[i]);
			m = max(suff_m, m);
		}
		//cout << m << endl;
		return m;
	}

	int maxSubarraySumCircular(vector<int>& A) {
		int s = 0;
		for (auto a : A) s += a;
		int s1 = dp(A, 0, A.size() - 1, 1);
		int s2 = s + dp(A, 0, A.size() - 2, -1);
		int s3 = s + dp(A, 1, A.size() - 1, -1);
		return max(s1, max(s2, s3));
	}
};

