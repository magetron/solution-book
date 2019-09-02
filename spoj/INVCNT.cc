#include <bits/stdc++.h>

using namespace std;

void convert (vector<int>& arr) {
	int len = arr.size();
	vector<int> cpy = arr;
	sort(cpy.begin(), cpy.end());
	for (int i = 0; i < len; i++) arr[i] = lower_bound(cpy.begin(), cpy.end(), arr[i]) - cpy.begin() + 1;
}

void update (vector<int>& bit, int n, int i, int val) {
	while (i <= n) {
		bit[i] += val;
		i += i & (- i);
	}
}

int get_sum (vector<int>& bit, int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= i & (- i);
	}
	return ans;
}

void do_work () {
    int n;
    cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	convert(arr);
	//for (auto it = arr.begin(); it != arr.end(); it++) cout << *it << " ";
	//cout << endl;

	vector<int> bit(arr.size() + 1, 0);
	long ans = 0;
	for (int i = arr.size() - 1; i >= 0; i--) {
		ans += get_sum(bit, arr[i] - 1);
		update(bit, arr.size(), arr[i], 1);
	}
	cout << ans << endl;
	return;
}

int main () {
    freopen("INVCNT.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) do_work();
    fclose(stdin);
    return 0;
}
 
