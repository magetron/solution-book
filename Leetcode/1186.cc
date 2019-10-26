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
    int maximumSum(vector<int>& arr) {
		vector<int> f(arr.size());
		vector<int> b(arr.size());
		int suff_m = arr[0];
		int m = arr[0];
		f[0] = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			suff_m = max(suff_m + arr[i], arr[i]);
			m = max(suff_m, m);
			f[i] = suff_m;
		}
		suff_m = arr.back();
		b[arr.size() - 1] = arr.back();
		for (int i = arr.size() - 2; i >= 0; i--) {
			suff_m = max(suff_m + arr[i], arr[i]);
			b[i] = suff_m;
		}
		for (int i = 1; i < arr.size() - 1; i++) {
			m = max(m, f[i - 1] + b[i + 1]);
		}
		return m;
	}
};
