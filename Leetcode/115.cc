#include<bits/stdc++.h>
#pragma clang optimize on

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
		vector<long> dp(t.length(), 0);
		for (int i = 0; i < s.length(); i++)
			for (int j = t.length(); j >= 0; j--) 
				if (s[i] == t[j]) {
					if (j == 0) dp[j]++; else dp[j] += dp[j - 1];
				}
		return (int)dp[t.length() - 1];
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s("rabbbit");
	string t("rabbit");
	Solution sol;
	cout << sol.numDistinct(s, t) << endl;
	return 0;
}
