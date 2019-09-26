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
    bool isOneEditDistance(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1));
		dp[0][0] = 0;
		for (int i = 0; i < s.length(); i++) dp[i + 1][0] = i + 1;
		for (int j = 0; j < t.length(); j++) dp[0][j + 1] = j + 1;
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j < t.length(); j++)
				if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
				else dp[i + 1][j + 1] = 1 + min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]);
		return (dp[s.length()][t.length()] == 1);
    }
};


