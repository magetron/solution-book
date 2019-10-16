#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
    	string s;
		for (auto str : strs) {
			s += to_string(str.length()) + "@" + str;
		}
		return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int p = 0;
		vector<string> ans;
		while (p < s.length()) {
			int atpos = s.find_first_of('@', p);
			int len = stoi(s.substr(p, atpos - p));
			ans.push_back(s.substr(atpos + 1, len));
			p = atpos + 1 + len;
		}
		return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

