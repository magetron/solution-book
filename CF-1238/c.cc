#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


void do_work () {
	int h, n;
	cin >> h >> n;
	vector<int> lev(n);
	for (int i = 0; i < n; i++) cin >> lev[i];
	int ans = 0;
	int lf = 0;
	for (int i = 1; i < n; i++) {
		if (lev[i - 1] > lev[i] + 1) {
			if (lf > 0) ans += (i - lf) & 1;
			else ans += 1 - ((i - lf) & 1);
			lf = i;
		}
	}
	if (lev[n - 1] > 1) {
		if (lf != 0) ans += (n - lf) & 1;
		else ans += 1 - ((n - lf) & 1);
	}
	cout << ans << endl;
}

int main () {
	int q;
	cin >> q;
	while (q--) {
		do_work();
	}
	return 0;
}
