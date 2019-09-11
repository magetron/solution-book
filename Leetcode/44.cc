#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, i_star = - 1, j_star = - 1;
		while (i < s.length()) {
			if (j < p.length() && (s.at(i) == p.at(j) || p.at(j) == '?')) { i++; j++; }
			else if (j < p.length() && p.at(j) == '*') {
				i_star = i;
				j_star = j;
				j++;
			}
			else if (i_star != -1) {
				i = ++i_star;
				j = j_star + 1;
			} else return false;
		}
		while (j < p.length()) if (p.at(j) != '*') return false; else j++;
		return j == p.length();
    }
};

