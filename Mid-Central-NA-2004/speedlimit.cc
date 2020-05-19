#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == -1) break;
		int ans = 0;
		int prev = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			ans += (b - prev) * a;
			prev = b;
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}
