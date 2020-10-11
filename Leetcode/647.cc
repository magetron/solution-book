#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int countSubstrings(string s) {
			vector<vector<bool>> dp (5001, vector<bool>(5001, false));
			int ans = s.length();

			for(size_t i = 0; i < s.length(); i++) {
				dp[i][i] = true;
			}
			for(size_t i=0; i < s.length() - 1; i++) {
				if(s[i] == s[i + 1]) {
					dp[i][i + 1] = true;
					ans++;
				}
			}
			for(size_t i = 2; i < s.length(); i++) {
				for(size_t j = 0; j < i; j++) {
					if(s[i] == s[j] && dp[j + 1][i - 1]) {
						dp[j][i] = true;
						ans++;
					}
				}
			}
			return ans;
		}
};

