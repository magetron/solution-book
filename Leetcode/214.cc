#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
		reverse(s.begin(), s.end());
        //cout << s << endl;
		int pos = -1;
		for (int b = 0; b < s.length(); b++) {
			int i = b;
			int j = s.length() - 1;
			while (s[i] == s[j] && i < j) { i++; j--; }
			if (j <= i) {
				pos = b;
				break;
			}
		}
		string astr = s.substr(0, pos);
        //cout << pos << " " << astr << endl;
		reverse(astr.begin(), astr.end());
		s += astr;
		reverse(s.begin(), s.end());
		return s;
    }
};

