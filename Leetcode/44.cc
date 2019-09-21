#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
    	int i = 0, j = 0;
		int iStar = -1, jStar = -1;
		while (i < s.length()) 
			if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
				i++; j++;
			} else if (j < p.length() && p[j] == '*') {
				iStar = i;
				jStar = j++;
			} else if (jStar != - 1) {
				i = ++iStar;
				j = jStar + 1;
			} else return false;
		while (j < p.length() && p[j] == '*') j++;
		return j == p.length();
    }
};

