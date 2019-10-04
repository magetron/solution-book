#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
	
	vector<int> build_lps (string& p) {
		vector<int> lps(p.length());
		int i = 0;
		lps[0] = 0;
		int j = 1;
		while (j < p.length()) {
			if (p.at(j) == p.at(i)) {
				i++;
				lps[j] = i;
				j++;
			} else if (i != 0) i = lps[i - 1];
			else {
				lps[j] = 0;
				j++;
			}
		}
		return lps;
	}

    string shortestPalindrome(string s) {
		string s1 = s;
		reverse(s1.begin(), s1.end());
		string ss = s + "#" + s1;
		auto lps = build_lps(ss);
		//for (auto i : lps) cout << i << " "; cout << endl;
		return s1.substr(0, s.length() - lps.back()) + s;
    }
};

int main () {
	Solution s;
	string st("aacecaaa");
	cout << s.shortestPalindrome(st) << endl;
	return 0;
}


