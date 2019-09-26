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
    bool isOneEditDistance(string s, string t) {
		s.push_back(' ');
		t.push_back(' ');
		int i = 0;
		int j = 0;
		bool diff = false;
		while (i < s.length() && j < t.length()) {
			if (s[i] == t[j]) { i++; j++; }
			else if (diff) return false;
			else {
				diff = true;
				if (s[i] == t[j + 1]) {
					i = i + 1;
					j = j + 2;
				} else if (s[i + 1] == t[j]) {
					i = i + 2;
					j = j + 1;
				} else if (s[i + 1] == t[j + 1]) {
					i = i + 2;
					j = j + 2;
				} else return false;
			}
		}
		return diff;
    }
};




