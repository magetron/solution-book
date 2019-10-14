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
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0;
	int c = a.size() - 1;
	int ans = 0;
	while (c >= 0 && a[c] > l) {
		int sp = a[c]; c--;
		while (c >= 0 && a[c] == sp) c--;
		l += r;
		ans++;
	}
	cout << ans << endl;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		do_work();
	}
	return 0;
}
