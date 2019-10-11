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

	vector<int> eval (string& s, int l, int r) {
		vector<int> ans;
		for (int i = l; i <= r; i++) {
			if (!isdigit(s[i])) {
				vector<int> l_sum = eval(s, l, i - 1);
				vector<int> r_sum = eval(s, i + 1, r);
				for (int ls : l_sum)
					for (int rs : r_sum)
						switch (s[i]) {
							case '+':
								ans.push_back(ls + rs);
								break;
							case '-':
								ans.push_back(ls - rs);
								break;
							case '*':
								ans.push_back(ls * rs);
								break;
						}
			}
		}
		if (ans.empty()) return {stoi(s.substr(l, r - l + 1))};
		else return ans;
	}

    vector<int> diffWaysToCompute(string s) {
		return eval(s, 0, s.length() - 1);
	}
};

int main () {
	Solution s;
	auto ans = s.diffWaysToCompute("1+2*3");
	for (auto i : ans) cout << i << " "; cout << endl;
	return 0;
}
