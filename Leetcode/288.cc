#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class ValidWordAbbr {
public:

	unordered_map<string, string> dict;

	inline string convert (string w) {
		string abbr;
		if (w.length() <= 2) abbr = w;
		else {
			abbr.push_back(w[0]);
			abbr += to_string(w.length() - 2);
			abbr.push_back(w.back());
		}
		return abbr;
	}

	ValidWordAbbr(vector<string>& dictionary) {
		for (string w : dictionary) {
			string abbr = convert(w);
			if (dict.find(abbr) != dict.end() && w != dict[abbr]) dict[abbr] = "";
			else dict.insert({abbr, w});
		}
    }
    
    bool isUnique(string word) {
		string abbr = convert(word);
		return (dict.find(abbr) == dict.end() || dict[abbr] == word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

