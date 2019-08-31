#include <bits/stdc++.h>
#define MAX_N 100005
#define MAX_X 1000000000

using namespace std;

bool doable (long long* stall, long long x, int n, int c) {
	bool ans = true;
	int c_left = c - 1;
	int i = 0;
	long long cur = stall[0];
	while (c_left > 0) {
		for (i = i + 1; stall[i] < cur + x && i < n; i++);
		if (i >= n) break;
		cur = stall[i];
		c_left--;
	}
	if (i >= n) return false;
	else return true;
}

int bin (long long* stall, int n, int c) {
	long long l = 0;
	long long h = stall[n - 1] - stall[0];
	long long max = 0;
	while (l <= h) {
		long long mid = (l + h) / 2;
		//cout << l << " " << h << " " << mid << endl;
		if (doable(stall, mid, n, c)) {
			l = mid + 1;
			max = mid;
		}
		else h = mid - 1;
	}
	return max;
}

void do_work () {
	int n, c;
	cin >> n >> c;
	long long *stall = new long long[n];
	for (int i = 0; i < n; i++) cin >> stall[i];
	sort(stall, stall + n, less<long long>());
	//for (int i = 0; i < n; i++) cout << stall[i] << " ";
	//cout << endl;
	//cout << doable(stall, 3, n, c);
	int ans = bin(stall, n, c);
	cout << ans << endl;
	delete [] stall;
	// binary search to narrow down
}



int main () {
	freopen("AGGRCOW.in", "r", stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) do_work();
	
	fclose(stdout);
	return 0;
}
