#include<bits/stdc++.h>
#define si short int
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	bool isPalin (string&s, int i, int j, vector<vector<si>>& dp) {
		if (dp[i][j] != -1) return dp[i][j];
		while (i < j) 
			if (s[i] != s[j]) {
				dp[i][j] = 0;
				return false;
			} else { i++; j--; }
		dp[i][j] = 1;
		return true;
	}

	void dfs (string& s, int i, vector<string>& path, vector<vector<string>>& ans, vector<vector<si>>& dp) {
		if (i == s.length()) {
			ans.push_back(path);
			return;
		}
		for (int j = i; j < s.length(); j++) 
			if (isPalin(s, i, j, dp)) {
				//cout << i << " " << j << endl;
				path.push_back(s.substr(i, j - i + 1));
				dfs(s, j + 1, path, ans, dp);
				path.pop_back();
			}
	}

    vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> path;
		vector<vector<si>> dp(s.length(), vector<si>(s.length(), - 1));
		dfs(s, 0, path, ans, dp);
		return ans;
    }
};

int main () {
	Solution s;
	auto ans = s.partition("acbca");
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}
