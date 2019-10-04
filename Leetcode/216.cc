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

	void dfs(vector<int>& path, vector<vector<int>>& ans, int k, int n) {
		//cout << k << " " << n << endl;
		//cout << "path = "; for (auto i : path) cout << i << " "; cout << endl;
		if (n > k * 9) return;
		if (k == 1) {
			if (n > 0 && n <= 9 && n > path.back()) {
				ans.push_back(path);
				ans.back().push_back(n);
			}
			return;
		}
		int last = path.size() > 0 ? path.back() : 0;
		for (int i = last + 1; i <= n - k + 1 && i <= 9; i++) {
			path.push_back(i);
			dfs(path, ans, k - 1, n - i);
			path.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
   		vector<vector<int>> ans;
		vector<int> path;
		dfs(path, ans, k, n);
    	return ans;
	}
};

int main () {
	Solution s;
	auto ans = s.combinationSum3(3, 9);
	for (auto as : ans) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}
