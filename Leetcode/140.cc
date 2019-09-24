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


	void fill (string& s, vector<string>& path, vector<vector<int>>& dp, vector<string>& ans, int pos) {
		if (pos == 0) {
			string str = "";
			for (auto it = path.rbegin(); it != path.rend(); it++) str += *it + " ";
			str.pop_back();
			ans.push_back(str);
			return;
		}
		for (auto new_pos : dp[pos]) {
			path.push_back(s.substr(new_pos, pos - new_pos));
			fill(s, path, dp, ans, new_pos);
			path.pop_back();
		}
	}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict;
		int max_len = 0;
		for (string s : wordDict) {
			dict.insert(s);
			max_len = max(max_len, (int)s.length());
		}
        vector<vector<int>> dp(s.length() + 1, vector<int>());
		dp[0] = vector<int>{0};
		for (int i = 0; i < s.length(); i++) 
			for (int j = 1; j <= i + 1 && j <= max_len; j++)
				if (dp[i - j + 1].size() != 0) {
					string sub_str = s.substr(i - j + 1, j);
					auto found = dict.find(sub_str);
					if (found != dict.end()) dp[i + 1].push_back(i - j + 1);
				}
		/*for (int i = 0; i < dp.size(); i++) {
			cout << i << " ";
			for (auto j : dp[i]) cout << j << " ";
			cout << endl;
		}*/
		vector<string> ans;
		vector<string> path;	
		fill(s, path, dp, ans, s.length());
		return ans;
    }
};

int main () {
	Solution s;
	vector<string> dict{"cat", "cats", "and", "sand", "dog"};
	auto ans = s.wordBreak("catsanddog", dict);
	for (auto s : ans) cout << s << endl;
	return 0;
}


