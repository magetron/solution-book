#include <bits/stdc++.h>
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
    vector<vector<int>> combine(int n, int k) {
      	vector<vector<int>> ans;
		vector<int> c(k, 0);
		int i = 0;
		while (i >= 0) {
			c[i]++;
			if (c[i] > n) i--;
			else if (i == k - 1) ans.push_back(c);
			else {
				i++;
				c[i] = c[i - 1];
			}
		}
		return ans;
    }
};

int main () {
	Solution s;
	cout << s.longestValidParentheses(")()())") << endl;
	return 0;
}

