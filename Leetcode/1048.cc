#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), [] (const string& a, const string& b) -> bool {
				return a.length() < b.length();
			});
		unordered_map<string, int> dp;
		int ans = 0;
		for (string w : words) {
			dp[w] = 1;
			for (int i = 0; i < w.length(); i++) {
				string ns = w.substr(0, i) + w.substr(i + 1, w.length() - i - 1);
				dp[w] = max(dp[w], (dp.find(ns) == dp.end() ? 0 : dp[ns]) + 1);
			}
			ans = max(ans, dp[w]);
		}
		return ans;
    }
};

