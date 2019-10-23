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


	bool match (string str, int i, string pattern, int j, vector<string>& dict, unordered_set<string>& allw) {
		if (i == str.length() && j == pattern.length()) return true;
		else if (i == str.length() || j == pattern.length()) return false;

		if (dict[pattern[j] - 97] != "@") {
			string s = dict[pattern[j] - 97];
            //cout << s << endl;
            //cout << str.find(s, i) << " " << i << endl;
			if (str.find(s, i) == i) return match(str, i + s.length(), pattern, j + 1, dict, allw);
			else return false;
		}

		for (int k = i; k < str.length(); k++) {
			string s = str.substr(i, k - i + 1);
			if (allw.find(s) != allw.end()) continue;
			dict[pattern[j] - 97] = s;
			allw.insert(s);
			if (match(str, k + 1, pattern, j + 1, dict, allw)) return true;
			dict[pattern[j] - 97] = "@";
			allw.erase(s);
		}	
		return false;
	}

    bool wordPatternMatch(string pattern, string str) {
		vector<string> dict(26, "@");
		unordered_set<string> allw;
		return match(str, 0, pattern, 0, dict, allw);
    }
};

