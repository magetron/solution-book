#include <bits/stdc++.h>
#define si short int
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

	bool dfs (string s, int l, unordered_map<string, int>& dict, int max_len, vector<si>& dp) {
		if (l == s.length()) return true;
		if (dp[l] != -1) return (dp[l] == 1);
		string new_str = "";
		for (int i = l; i < l + max_len && i < s.length(); i++) {
			new_str.push_back(s[i]);
			auto found = dict.find(new_str);
			if (found != dict.end()) {
                //cout << new_str << endl;
				dict[new_str]++;
				bool res = dfs(s, i + 1, dict, max_len, dp);
				dp[i + 1] = (res ? 1 : 0); 
				if (res) return true;
				dict[new_str]--;
			}
		}
		return false;
	}

    bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, int> dict;
		int max_len = 0;
		for (string s : wordDict) {
			dict.insert({s, 0});
			max_len = max(max_len, (int)s.length());
		}
		vector<si> dp(s.length() + 1, -1);
		return dfs(s, 0, dict, max_len, dp);
    }
};

