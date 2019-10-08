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
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		ll a = A, b = B, c = C, d = D, e = E, f = F, g = G, h = H;
		ll ans = abs(c - a) * abs(d - b) + abs(g - e) * abs(h - f);
		ll aa;
		if (max(a, c) <= max(g, e) && min(g, e) <= min(a, c)) aa = abs(c - a);
		else if (max(g, e) <= max(a, c) && min(a, c) <= min(g, e)) aa = abs(g - e);
		else if (max(a, c) < min(g, e) || max(g, e) < min(a, c)) aa = 0;
		else aa = min(max(a, c) - min(g, e), max(g, e) - min(a, c));
		//cout << a << endl;
		ll bb;
		if (max(b, d) <= max(h, f) && min(h, f) <= min(b, d)) bb = abs(b - d);
		else if (max(h, f) <= max(b, d) && min(b, d) <= min(h, f)) bb = abs(h - f);
		else if (max(b, d) < min(h, f) || max(h, f) < min(b, d)) bb = 0;
		else bb = min(max(b, d) - min(h, f), max(h, f) - min(b, d));
		//cout << b << endl;
		return ans - aa * bb;
	}
};


int main () {
	Solution s;
	cout << s.computeArea(-3,0,3,4,0,-1,9,2) << endl;
	return 0;
}
