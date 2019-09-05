#include <bits/stdc++.h>
#define ll long long
using namespace std;

void update (vector<ll>& bit, ll i, ll val) {
	while (i < bit.size()) {
		bit[i] += val;
		i += (i & (-i));
	}
}

ll get_sum (vector<ll>& bit, ll i) {
	ll ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void do_work () {
	ll n, c;
	cin >> n >> c;
	vector<ll> bit1(n + 1, 0);
	vector<ll> bit2(n + 1, 0);
	while (c--) {
		ll type, p, q, v;
		cin >> type;
		if (type == 0) {
			cin >> p >> q >> v;
			update(bit1, p, v);
			update(bit1, q + 1, - v);
			update(bit2, p, v * (p - 1));
			update(bit2, q + 1, - v * q); 
		} else {
			cin >> p >> q;
			cout << (get_sum(bit1, q) * q - get_sum(bit2, q)) - 
					(get_sum(bit1, p - 1) * (p - 1) - get_sum(bit2, p - 1)) << endl;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("HORRIBLE.in", "r", stdin);
	ll t;
	cin >> t;
	while (t--) do_work();
	fclose(stdout);
	return 0;
}
