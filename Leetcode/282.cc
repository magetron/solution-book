#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

#define ll long long

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	void dfs (int pos, string& p, string& num, int& target, ll cur, ll prev, vector<string>& ans) {
		if (pos == num.length()) {
			//if (eval(path) == (ll)target) ans.push_back(path);
			if ((ll)target == cur) ans.push_back(p);
			return;
		}
		for (int i = pos; i < num.length(); i++) {
			if (num[pos] == '0' && i > pos) break;
			string s = num.substr(pos, i - pos + 1);
			ll val = stol(s);
			if (pos == 0) {
				p += s;
				dfs(i + 1, p, num, target, val, val, ans);
				p.erase(p.end() - s.length(), p.end());
			} else {
				p += "+" + s;
				dfs(i + 1, p, num, target, cur + val, val, ans);
				p.erase(p.end() - s.length() - 1, p.end());
				p += "-" + s;
				dfs(i + 1, p, num, target, cur - val, -val, ans);
				p.erase(p.end() - s.length() - 1, p.end());
				p += "*" + s;
				dfs(i + 1, p, num, target, cur - prev + prev * val, prev * val, ans);
				p.erase(p.end() - s.length() - 1, p.end());
			}
		}		
	}		

    vector<string> addOperators(string num, int target) {
		if (!num.length()) return {};
		vector<string> ans;	
		string path;
		dfs(0, path, num, target, 0, 0, ans);
		//path.clear();
		//path.push_back('-'); path.push_back(num[0]);
		//dfs(1, path, num, target, ans);
		return ans;
	}
};
