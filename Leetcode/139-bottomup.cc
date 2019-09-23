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
	bool wordBreak(string s, vector<string>& wordDict) {
    	unordered_set<string> dict;
		int max_len = 0;
		for (string s : wordDict) {
			dict.insert(s);
			max_len = max(max_len, (int)s.length());
		}
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 0; i < s.length(); i++)
			for (int j = 1; j <= i + 1 && j <= max_len; j++) 
                if (dp[i - j + 1]) {
                    //cout << i << " " << j << endl;
                    string sub_str = s.substr(i - j + 1, j);
                    //cout << sub_str << endl;
    				auto found = dict.find(sub_str);
				    if (found != dict.end()) {
					    dp[i + 1] = true;
					    break;
				    }
                }
		return dp[s.length()];
    }
};

