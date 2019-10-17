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
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int pen = ceil(a * 1.0 / c);
	int pencil = ceil(b * 1.0 / d);
	if (pen + pencil > k) cout << -1 << endl;
	else cout << pen << " " << pencil << endl;
}

int main () {
	int t;
	cin >> t;
	while (t--) do_work();
	return 0;
}
