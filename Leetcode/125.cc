#include <bits/stdc++.h>

using namespace std;

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
} ();


class Solution {
	public:
		
		bool valid (char ch) {
			return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'));
		}
		
		bool isPalindrome(string s) {
			int i = 0;
			int j = s.length() - 1;
			while (i < j) {
				if (!valid(s[i])) i++;
				else if (!valid(s[j])) j--;
				else if (tolower(s[i]) == tolower(s[j])) {
					i++;
					j--;
				} else return false;
			}
			return true;
		}
};
