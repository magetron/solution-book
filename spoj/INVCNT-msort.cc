#include <bits/stdc++.h>

using namespace std;

long long merge (long long l, long long r, vector<int>& arr, int low, int mid, int high) {
	vector<int> tmp;
	long long ans = l + r;
	int i = low, j = mid + 1;
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
		else {
			tmp.push_back(arr[j++]);
			ans += (mid - i) + 1;
		}
	}
	while (i <= mid) tmp.push_back(arr[i++]);
	while (j <= high) tmp.push_back(arr[j++]);
	for (int i = low; i <= high; i++) arr[i] = tmp[i - low];
	return ans;
}



long long solve (vector<int>& arr, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		return merge(solve(arr, low, mid), solve(arr, mid + 1, high), arr, low, mid, high);
		//cout << tmp_res << " " << low << " " << high << endl;
	} else return 0;
}
		


void do_work () {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << solve(arr, 0, n - 1) << endl;
	return;
}

int main () {
	freopen("INVCNT.in", "r", stdin);
	//freopen("INVCNT.ans", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) do_work();
	fclose(stdin);
	//fclose(stdout);
	return 0;
}
