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


void do_work () {
	ll x, y;
	cin >> x >> y;
	cout << (x - y > 1 ? "YES" : "NO") << endl;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		do_work();
	}
	return 0;
}
