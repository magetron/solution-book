#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int minCut(string s) {
		vector<int> dp(s.length());
		for (int i = 0; i < s.length(); i++) dp[i] = i;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; i - j >= 0 && i + j < s.length() && s[i + j] == s[i - j]; j++) 
				dp[i + j] = min(dp[i + j], 1 + ((i - j - 1 >= 0) ? dp[i - j - 1] : -1));
			for (int j = 0; i - j - 1 >= 0 && i + j < s.length() && s[i - j - 1] == s[i + j]; j++) 
				dp[i + j] = min(dp[i + j], 1 + ((i - j - 2 >= 0) ? dp[i - j - 2] : -1));
		}
		return dp[s.length() - 1];
	}
};

int main () {
	Solution s;
	int ans = s.minCut("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj");
	cout << ans << endl;
	return 0;
}
