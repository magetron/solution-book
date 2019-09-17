#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if (s.length() == 0) return 0;
		vector<int> dp(s.length());
		if (s[0] == '0') return 0;
		if (s.length() == 1) return 1;
		dp[0] = 1;
		for (int i = 1; i < s.length(); i++) 
			if (s[i] != '0') {
				if ((s[i - 1] - 48) * 10 + s[i] - 48 <= 26 && s[i - 1] != '0') dp[i] = dp[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 1);
				else dp[i] = dp[i - 1];
			} else { 
				if (s[i - 1] != '1' && s[i - 1] != '2') return 0; else dp[i] = (i - 2 >= 0 ? dp[i - 2] : 1);
			}
		return dp[s.length() - 1];
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	cout << s.numDecodings("110") << endl;
	return 0;
}
