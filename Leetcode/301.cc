#include<bits/stdc++.h>
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
	inline void remove(string s, vector<string>& ans, int last_i, int last_j, pair<char, char> paren) {
		for (int stack = 0, i = last_i; i < s.length(); i++) {
			if (s[i] == paren.first) stack++;
			else if (s[i] == paren.second) stack--;
			if (stack < 0) {
				for (int j = last_j; j <= i; j++)
					if (s[j] == paren.second && (j == last_j || s[j - 1] != paren.second))
							remove(s.substr(0, j) + s.substr(j + 1, s.length() - j - 1), ans, i, j, paren);
				return;
			}
		}
		string rev(s.rbegin(), s.rend());
		if (paren.first == '(')
			remove(rev, ans, 0, 0, {')', '('});
		else 
			ans.push_back(rev);
	}

    vector<string> removeInvalidParentheses(string s) {
		vector<string> ans;
		remove(s, ans, 0, 0, {'(', ')'});
		return ans;
    }
};
