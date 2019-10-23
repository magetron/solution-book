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
    bool canWin(string& s) {
        if (!s.length()) return false;
    	for (int i = 0; i < s.length() - 1; i++)
			if (s[i] == '+' && s[i + 1] == '+') {
				s[i] = s[i + 1] = '-';
				bool win = !canWin(s);
				s[i] = s[i + 1] = '+';
				if (win) return true;
			}
		return false;
	}
};

