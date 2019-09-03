#include <bits/stdc++.h>

using namespace std;

int numTrees (int n) {
	vector<int> dp(n > 1 ? n + 1 : 3, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	if (n <= 2) return dp[n];
	for (int i = 3; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			dp[i] += dp[j - 1] * dp[i - j];
	return dp[n];
}

int main () {
	cout << numTrees(3) << endl;
	return 0;
}

