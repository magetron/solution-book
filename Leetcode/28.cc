#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	vector<int> build_lps (string& p) {
		vector<int> lps (p.length());
		lps[0] = 0;
		int i = 0;
		int j = 1;
		while (j < p.length()) 
			if (p[i] == p[j]) {
				i++;
				lps[j] = i;
				j++;
			} else if (i != 0) i = lps[i - 1];
			else {
				lps[j] = 0;
				j++;
			}
		return lps;
	}

	int kmp (string& s, string& p) {
		int i = 0;
		int j = 0;
		vector<int> lps = build_lps(p);
		while (i < s.length()) {
			while (i < s.length() && j < p.length() && s[i] == p[j]) { i++; j++; }
			if (j == p.length()) return i - p.length();
			if (j != 0) j = lps[j - 1]; else i++;
		}
		return -1;
	}

    int strStr(string s, string p) {
        if (p.length() == 0) return 0;
		if (s.length() == 0) return -1;
		if (p.length() > s.length()) return -1;
		//for (auto it = lps.begin(); it != lps.end(); it++)
		//	cout << *it << " ";
		return kmp(s, p);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution sol;
	string s("hello");
	string p("lo");
	cout << sol.strStr(s, p) << endl;
	return 0;
}

