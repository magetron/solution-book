#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
} ();

int main () {
	int n;
	cin >> n;
	vector<int> hs(n);
	for (int i = 0; i < n; i++) cin >> hs[i];
	int i = 0, ans = 0;
	while (i < hs.size() - 1)
		if (hs[i] > hs[i + 1]) {
			int j = i + 1;
			while (j < hs.size() - 1 && hs[j] >= hs[j + 1]) j++;
			j += 1;
			if (j == hs.size()) {
				cout << ans << endl;
				return 0;
			} else {
				ans++;
				i = j;
			}
		} else i++;
	cout << ans << endl;
	return 0;
}

