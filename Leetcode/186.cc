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
    void reverseWords(vector<char>& s) {
		reverse(s.begin(), s.end());
		int i = 0;
		while (i < s.size()) {
			int j = i + 1;
			while (j < s.size() && s[j] != ' ') j++;
			int l = i;
			int r = j - 1;
			while (l < r) {
				swap(s[l], s[r]);
				l++;
				r--;
			}
			i = j + 1;
		}
    }
};

