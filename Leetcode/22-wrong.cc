#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> generateParenthesisUtil(int n) {
		if (n == 0) return unordered_set<string>();
		unordered_set<string> ans;
		if (n == 1) {
			string s("()");
				ans.insert(s);
			return ans;
		}
		unordered_set<string> prev_ans = generateParenthesisUtil(n - 1);
		for (auto it = prev_ans.begin(); it != prev_ans.end(); it++) {
			string s = *it;
			ans.insert("(" + s + ")");
			ans.insert("()" + s);
			ans.insert(s + "()");
		}

		/*for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << endl;	
		cout << "-----------" << endl;*/
		return ans;
    }
	
    vector<string> generateParenthesis(int n) {
		unordered_set<string> ans = generateParenthesisUtil(n);
		vector<string> ret;
		ret.reserve(ans.size());
		for (auto const& str : ans) ret.emplace_back(str);
		return ret;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<string> ans = s.generateParenthesis(3);
	for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << endl;	
	return 0;
}
