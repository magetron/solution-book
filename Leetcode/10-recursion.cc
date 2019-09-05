#include<bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool isMatch (string s, string p) {
			if (p.length() == 0) return s.length() == 0;
			bool match = (!(s.length() == 0) && (s.at(0) == p.at(0) || p.at(0) == '.'));
			bool rep = false;
			if (p.length() >= 2 && p.at(1) == '*') rep = true;
			if (rep) 
				return (isMatch(s, p.substr(2, p.length() - 2)) ||
						(match && isMatch(s.substr(1, s.length() - 1), p)));
			else
				return (match && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)));
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	string str("aa");
	string pattern("a");
	cout << (s.isMatch(str, pattern) ? "true" : "false") << endl;
	return 0;
}

