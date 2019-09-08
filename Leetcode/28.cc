#include <bits/stdc++.h>

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
				lps[j] = lps[j - 1] + 1;
				i++;
			}
			j++;
		}
		return lps;
	}

	int kmp (string& s, string& p, vector<int>& lps) {
		int i = 0;
		while (i < s.length() - p.length() + 1) {
			//cout << i << endl;
			int j = i;
			int k = 0;
			while (j < s.length() && k < p.length() && s.at(j) == p.at(k)) { 
				j++; k++; 
			}
			if (k == p.length()) return i;
			else i += 1 + lps[k];
		}
		return -1;
	}

    int strStr(string s, string p) {
        if (p.length() == 0) return 0;
		if (s.length() == 0) return -1;
		if (p.length() > s.length()) return -1;
		vector<int> lps = build_lps(p);
		//for (auto it = lps.begin(); it != lps.end(); it++)
		//	cout << *it << " ";
		return kmp(s, p, lps);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution sol;
	string s("a");
	string p("a");
	cout << sol.strStr(s, p) << endl;
	return 0;
}

