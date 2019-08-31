#include <bits/stdc++.h>
#define MAX_N 1000000005

using namespace std;

long long max (long long a, long long b) {
	return a > b ? a : b;
}

vector<long long> dp (MAX_N / 50, 0);

void pre_calc (long long n) {
		dp[0] = 0;
		dp[1] = 1;
		for (long long i = 2; i <= n; i++) {
			//cout << dp[i / 2] << " " << dp[i / 3] << " " << dp[i / 4] << endl;
			dp[i] = max(dp[i / 2] + dp[i / 3] + dp[i / 4], i);
		}
}

long long recur (long long n, long long t) {
	if (n <= t) return dp[n];
	else return recur(n / 2, t) + recur(n / 3, t) + recur(n / 4, t);
}

void do_work () {
	long long threshold = MAX_N / 50;
	pre_calc(threshold);
	long long n;
	while (cin >> n) {
		if (n > threshold) cout << recur(n, threshold) << endl;
		else cout << dp[n] << endl;
	}
}	

int main () {
	//freopen("COINS.in", "r", stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	do_work();
	//fclose(stdout);
	return 0;
}

