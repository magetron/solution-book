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
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= s1.length(); i++) {
			if (i == 0) {
				for (int j = 1; j <= s2.length(); j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
			} else {
				dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
				for (int j = 1; j <= s2.length(); j++) dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			}
		}
		return dp[s1.length()][s2.length()];
    }
};

