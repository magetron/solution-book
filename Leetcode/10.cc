#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool isMatch (string s, string p) {
			short int **dp = new short int*[s.length() + 1];
			for (int i = 0; i < s.length() + 1; i++) dp[i] = new short int[p.length() + 1];
			for (int i = 0; i < s.length() + 1; i++)
				for (int j = 0; j < p.length() + 1; j++) dp[i][j] = -1;
			return isMatchHelper(s, p, 0, 0, dp);
		}

		short int isMatchHelper (string& s, string& p, int i, int j, short int** dp) {
			//cout << i << " " << j << endl;
			if (i > s.length() || j > p.length()) return 0;
			if (dp[i][j] != -1) return dp[i][j];
			if (j == p.length()) {
				dp[i][j] = (i == s.length()) ? 1 : 0;
				return dp[i][j];
			}
			bool match = (i != s.length()) && (p.at(j) == s.at(i) || p.at(j) == '.');
			bool rep = false;
			if (j + 1 < p.length() && p.at(j + 1) == '*') rep = true;
			if (rep) {
				short int res = isMatchHelper(s, p, i, j + 2, dp) || (match && isMatchHelper(s, p, i + 1, j, dp));
				dp[i][j] = res;
				return res;
			} else {
				short int res = match && isMatchHelper(s, p, i + 1, j + 1, dp);
				dp[i][j] = res;
				return res;
			}
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	string str("aa");
	string pat("a*");
	cout << (s.isMatch(str, pat) ? "true" : "false") << endl;
	return 0;
}


