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
    vector<vector<string>> groupStrings(vector<string>& strings) {
		map<vector<int>, vector<string>> dict;
    	for (string s :strings) {
			vector<int> g(s.length() - 1);
			for (int i = 1; i < s.length(); i++) g[i - 1] = (s[i] - s[i - 1] < 0 ? s[i] + 26 - s[i - 1] : s[i] - s[i - 1]);
			//for (int i : g) cout << i << " ";
			//cout << s << endl;
			dict[g].push_back(s);
		}
		vector<vector<string>> ans;
		for (auto p : dict) {
			ans.push_back(p.second);
		}
		return ans;
	}
};

int main () {
	vector<string> strs{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
	Solution s;
	auto ans = s.groupStrings(strs);
	for (auto ss : ans) {
		for (auto s : ss) cout << s << " ";
		cout << endl;
	}
	return 0;
}
