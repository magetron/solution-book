#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void preprocess(string& s) {
		int i = 0;
		while (i < s.length()) {
			if (s.at(i) == '*') {
				int j = i + 1;
				while (j < s.length() && s.at(j) == '*') j++;
				s = s.substr(0, i) + s.substr(j - 1, s.length() - j + 1);
			}
			i++;
		}
	}

	bool isMatch(string s, string p) {
		preprocess(p);
		cout << p << endl;
		return isMatchHelper(s, p, 0, 0);
	}

    bool isMatchHelper(string& s, string& p, int i, int j) {
		cout << i << s.at(i) << " " << j << p.at(j) << endl;
		while (i < s.length() && j < p.length()) {
			cout << i << " " << j << endl;
			if (s.at(i) != p.at(j) && p.at(j) != '?' && p.at(j) != '*') return false;
			if (s.at(i) == p.at(j)) { i++; j++; }
			else if (p.at(j) == '?') { i++; j++; }
			else if (p.at(j) == '*') {
				char next_char = (j + 1 < p.length()) ? p.at(j + 1) : '$';
				if (next_char == '$') return true;
				else {
					int k = i;
					bool res = false;
					do {
						while (k < s.length() && s.at(k) != next_char && next_char != '?') k++;
						cout << "k = " << k << endl;
						if (k < s.length() && isMatchHelper(s, p, k, j + 1)) return true;
						k++;
					} while (k < s.length());
					return false;
				}
			}
		}
		while (j < p.length() && p.at(j) == '*') j++;
		return (i == s.length() && j == p.length());
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution sol;
	string s("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb");
	string p("**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
	return 0;
}

