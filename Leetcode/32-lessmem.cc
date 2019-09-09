#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int longestValidParentheses (string s) {
			int l = 0;
			int r = 0;
			int max = 0;
			for (auto it = s.begin(); it != s.end(); it++) {
				if (*it == '(') l++; else if (*it == ')') r++;
				if (r > l) { l = 0; r = 0; }
				else if (r == l && r << 1 > max) max = r << 1;
			}
			l = 0;
			r = 0;
			for (auto it = s.rbegin(); it != s.rend(); it++) {
				if (*it == '(') l++; else if (*it == ')') r++;
				if (l > r) { l = 0; r = 0; }
				else if (r == l && r << 1 > max) max = r << 1;
			}
			return max;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	string str(")(()())");
	cout << s.longestValidParentheses(str);
	return 0;
}

