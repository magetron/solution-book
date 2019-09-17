#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	bool valid (string& s) {
		long val = 0;
		if (s[0] == '0' && s.length() != 1) return false;
		for (auto it = s.begin(); it != s.end(); it++) val = val * 10 + (*it - 48);
		return val >= 0 && val <= 255;
	}

	void helper(string& s, int l, int dots, vector<string>& ans) {
		if (dots == 0) {
			string num_str = s.substr(l, s.length() - l);
			if (valid(num_str)) ans.push_back(s);
			return;
		}
		for (int i = l + 1; i <= l + 3 && i < s.length(); i++) {
			string num_str = s.substr(l, i - l);
			cout << num_str << endl;
			if (valid(num_str))	{
				s.insert(s.begin() + i, '.');
				cout << s << endl;
				helper(s, i + 1, dots - 1, ans);
				s.erase(s.begin() + i);
			}
		}
	}		

    vector<string> restoreIpAddresses(string s) {
		if (s.length() > 12) return vector<string>();
		vector<string> ans;
		helper(s, 0, 3, ans);
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	auto ans = s.restoreIpAddresses("25525511135");
	for (auto str : ans) cout << str << endl;
	return 0;
}
