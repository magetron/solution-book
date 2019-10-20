#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
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
		if (n == 1) return k;
		int diff = k * (k - 1);
		int same = k;
		for (int i = 2; i < n; i++) {
			int tmp = diff;
			diff = (diff + same) * (k - 1);
			same = tmp;
		}
		return diff + same;
    }
};

int main () {
	Solution s;
	cout << s.numWays(3, 2) << endl;
	return 0;
}



