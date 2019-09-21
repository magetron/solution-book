#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int longestValidParentheses(string s) {
			vector<int> dp(s.length(), 0);
			for (int i = 1; i < s.length(); i++) 
				if (s.at(i) == ')') {
					if (s.at(i - 1) == '(') dp[i] = (i - 2 < 0 ? 2 : dp[i - 2] + 2);
					else if (i - dp[i - 1] - 1 >= 0 && s.at(i - dp[i - 1] - 1) == '(') 
							dp[i] = (i - dp[i - 1] - 2 < 0) ? dp [i - 1] + 2 : dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
				}
			//for (auto i : dp) cout << i << " ";
			//cout << endl;
			int max = 0;
			for (auto i : dp) if (i > max) max = i;
			return max;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str("()())");
	Solution s;
	cout << s.longestValidParentheses(str) << endl;
	return 0;
}

