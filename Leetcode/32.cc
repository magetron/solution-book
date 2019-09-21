#include <bits/stdc++.h>
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
    int longestValidParentheses(string s) {
        int l = 0;
		int r = 0;
		int ans = 0;
		for (auto it = s.begin(); it != s.end(); it++) {
			if (*it == '(') l++; else r++;
			if (r > l) { r = 0; l = 0; }
			if (l == r) ans = max(ans, l);
		}
		l = 0; r = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++) {
			if (*it == '(') l++; else r++;
			if (l > r) { r = 0; l = 0; }
			if (l == r) ans = max(ans, l);
		}
		return ans << 1;
    }
};

int main () {
	Solution s;
	cout << s.longestValidParentheses(")()())") << endl;
	return 0;
}

