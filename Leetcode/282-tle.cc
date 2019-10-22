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

    ll calculate_simple(string s) {
		int i = 0, sign = 1; 
        ll n = 0, ans = 0;
		stack<ll> op, res;
		while (i < s.length()) {
			if (isdigit(s[i])) n = n * 10 + (s[i] - 48);
			else {
				ans += n * sign;
				n = 0;
				if (s[i] == '+') sign = 1;
				else if (s[i] == '-') sign = -1;
			}
			i++;
		}
		ans += n * sign;
		return ans;
    }

    ll eval(string S) {
		string s;
		for (auto ch : S) if (ch != ' ') s.push_back(ch);
		int i = 0;
		while (i < s.length()) {
			if (s[i] == '*' || s[i] == '/') {
    			int l = i - 1;
				while (l >= 0 && isdigit(s[l])) l--;
				int r = i + 1;
				while (r < s.length() && s[r] != '+' && s[r] != '-') r++;
				int j = l + 1;
				ll res = 1;
				ll n = 0;
				char sign = '*';
				while (j < r) {
					if (isdigit(s[j])) n = n * 10 + (s[j] - 48);
					else {
						if (sign == '*') res *= n; else res /= n;
						n = 0;
						sign = s[j];
					}
					j++;
				}
				if (sign == '*') res *= n; else res /= n;
				string r_str = to_string(res);
				s.replace(l + 1, r - l - 1, r_str);
				i = l + 1 + r_str.length();
			}
			i++;
		}
		return calculate_simple(s);
	}

	void dfs (int pos, string& path, string& num, int& target, vector<string>& ans) {
		if (pos == num.length()) {
			if (eval(path) == (ll)target) ans.push_back(path);
			//ans.push_back(path);
			return;
		}
		path.push_back('+'); path.push_back(num[pos]);
		dfs(pos + 1, path, num, target, ans);
		path.pop_back(); path.pop_back();
		path.push_back('-'); path.push_back(num[pos]);
		dfs(pos + 1, path, num, target, ans);
		path.pop_back(); path.pop_back();
		path.push_back('*'); path.push_back(num[pos]);
		dfs(pos + 1, path, num, target, ans);
		path.pop_back(); path.pop_back();
		if (num[pos - 1] != '0') {
			path.push_back(num[pos]);
			dfs(pos + 1, path, num, target, ans);
			path.pop_back();
		}
	}		

    vector<string> addOperators(string num, int target) {
		if (!num.length()) return {};
		vector<string> ans;	
		string path{num[0]};
		dfs(1, path, num, target, ans);
		//path.clear();
		//path.push_back('-'); path.push_back(num[0]);
		//dfs(1, path, num, target, ans);
		return ans;
	}
};

int main () {
	Solution s;
	auto ans = s.addOperators("1000000009", 9);
	for (auto s : ans) cout << s << endl;
	return 0;
}
