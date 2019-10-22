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
    bool wordPattern(string pattern, string str) {
		vector<string> dict(26, "@");
		int i = 0;
		for (char c : pattern) {
            if (i >= str.length()) return false;
			int j = i + 1;
			while (j < str.length() && str[j] != ' ') j++;
			string word = str.substr(i, j - i);
            cout << word << endl;
			if (dict[c - 97] == "@") dict[c - 97] = word;
			else if (dict[c - 97] != word) return false;
            i = j + 1;
		}
        if (i < str.length()) return false;
		for (int i = 0; i < 25; i++) if (dict[i] != "@")
			for (int j = i + 1; j < 26; j++) if (dict[j] != "@") {
				if (dict[i] == dict[j]) return false;
			}
		return true;
    }
};

