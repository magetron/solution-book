#include <bits/stdc++.h>
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
    string reverseWords(string s) {
    	reverse(s.begin(), s.end());
		int i = 0;
		while (s[i] == ' ') s.erase(i, 1);
		i = s.length() - 1;
		while (s[i] == ' ') {
			s.erase(i, 1);
			i--;
		}
		i = -1;
    	while (i < (int)s.length()) {
			int j = i + 1;
    		while (j < s.length() && s[j] != ' ') j++;
			int l = i + 1;
			int r = j - 1;
			while (l < r) {
				swap(s[l], s[r]);
				l++; r--;
			}
			int f_j = j + 1;
			while (f_j < s.length() && s[f_j] == ' ') s.erase(j, 1);
			i = j;
			//cout << i << endl;
    	}
		return s;
    }
};

int main () {
	Solution s;
	cout << s.reverseWords("  a good  example!  ") << endl;
	return 0;
}

