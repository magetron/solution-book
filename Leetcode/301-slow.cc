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

	bool isValid (string s) {
		stack<char> st;
		st.push('@');
		for (char ch : s) {
			if (ch == '(') st.push('(');
			else if (ch == '[') st.push('[');
			else if (ch == '{') st.push('{');
			else if (ch == ')') {
				if (st.top() != '(') return false; else st.pop();
			} else if (ch == ']') {
				if (st.top() != '[') return false; else st.pop();
			} else if (ch == '}') {
				if (st.top() != '{') return false; else st.pop();
			}
		}
		return st.top() == '@';
	}

	void dfs (string& s, string& path, int pos, int miss, int& min_miss, unordered_set<string>& ans) {
		if (pos == s.length()) {
			//cout << path << endl;
			if (isValid(path)) {
				ans.insert(path);
				min_miss = min(min_miss, miss);
			}
			return;
		}
		if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{' || s[pos] == ')' || s[pos] == ']' || s[pos] == '}') {
			path.push_back(s[pos]);
			dfs(s, path, pos + 1, miss, min_miss, ans);
			path.pop_back();
			if (miss < min_miss) dfs(s, path, pos + 1, miss + 1, min_miss, ans);
		} else {
			path.push_back(s[pos]);
			dfs(s, path, pos + 1, miss, min_miss, ans);
			path.pop_back();
		}
	}

    vector<string> removeInvalidParentheses(string s) {
		unordered_set<string> ans;
		string path = "";
		int min_miss = INT_MAX;
		dfs(s, path, 0, 0, min_miss, ans);
		return vector<string>(ans.begin(), ans.end());
    }
};

int main () {
	Solution s;
	auto ans = s.removeInvalidParentheses(")(f");
	for (auto a : ans) cout << a << endl;
	return 0;
}
