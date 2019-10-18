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
    int numWays(int n, int k) {
		if (n == 0) return 0;
		else if (n == 1) return k;
		int d = k * (k - 1);
		int s = k;
		for (int i = 2; i < n; i++) {
			int tmp = d;
			d = (d + s) * (k - 1);
			s = tmp;
		}
		return s + d;
    }
};


int main () {
	Solution s;
	cout << s.numWays(3, 2) << endl;
	return 0;
}



