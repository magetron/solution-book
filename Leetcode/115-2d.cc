class Solution {
public:
    int numDistinct(string s, string t) {
		if (s == "" || t == "") return 0;
		vector<vector<long>> dp(s.length(), vector<long>(t.length(), 0));
		if (s[0] == t[0]) dp[0][0] = 1; else dp[0][0] = 0;
		for (int i = 1; i < s.length(); i++)
			for (int j = 0; j < t.length(); j++) 
				if (j == 0 && s[i] == t[j]) dp[i][j] = dp[i - 1][j] + 1;
				else if (j == 0) dp[i][j] = dp[i - 1][j];
				else if (s[i] == t[j] && t[j] != t[j - 1]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
				else if (s[i] == t[j] && t[j] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j];
		//for (auto as : dp) {
		//	for (auto a : as) cout << a << " ";
		//	cout << endl;
		//}
		return (int)dp[s.length() - 1][t.length() - 1];
    }
};
