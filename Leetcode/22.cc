#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<vector<string>> dict(1, vector<string>(1, ""));
		for (int i = 1; i <= n; i++) {
			vector<string> ans;
			for (int j = 0; j < i; j++) {
				vector<string> as = dict[j];
				vector<string> bs = dict[i - 1 - j];
				for (auto ia = as.begin(); ia != as.end(); ia++)
					for (auto ib = bs.begin(); ib != bs.end(); ib++)
						ans.push_back("(" + *ia + ")" + *ib);
			}
			dict.push_back(ans);
		}
		return dict[n];
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<string> ans = s.generateParenthesis(4);
	for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << endl;	
	return 0;
}
