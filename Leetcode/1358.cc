#pragma optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	void dec(char& ch, uint32_t& a, uint32_t& b, uint32_t& c) {
		if (ch == 'a') a--;
		else if (ch == 'b') b--;
		else if (ch == 'c') c--;
	}

	void inc(char& ch, uint32_t& a, uint32_t& b, uint32_t& c) {
		if (ch == 'a') a++;
		else if (ch == 'b') b++;
		else if (ch == 'c') c++;
	}

	int numberOfSubstrings(string s) {
    	size_t i = 0, j = 0;
		uint32_t cA = 0, cB = 0, cC = 0;
		inc(s[j], cA, cB, cC);
		int ans = 0;
		while (i <= j) {
			if (cA && cB && cC) {
				ans += s.length() - j;
				dec(s[i], cA, cB, cC);
				i++;
			} else {
				j++;
				if (j >= s.length()) break;
				inc(s[j], cA, cB, cC);
			}
		}
		return ans;
	}			
};

