#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ull unsigned long long

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;
		vector<char> d(128, 0);
        vector<bool> b(128, true);
		for (int i = 0; i < s.length(); i++) {
			if (d[s[i]] == 0) {
                if (b[t[i]]) {
                    d[s[i]] = t[i];
                    b[t[i]] = false;
                } else return false;
            }
			else if (t[i] != d[s[i]]) return false;
		}
		return true;
    }
};

