#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	int len1 = text1.length();
	int len2 = text2.length();
	vector<vector<int>> dp (len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++) 
			if (text1.at(i - 1) == text2.at(j - 1)) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[len1][len2];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1("abcde");
	string s2("ace");
	cout << longestCommonSubsequence(s1, s2) << endl;
	return 0;
}

