#include<bits/stdc++.h>

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	void dfs (int n, vector<int>& path, vector<vector<int>>& ans, int& on) {
		for (int i = path.empty() ? 2 : path.back(); i <= trunc(sqrt(n)); i++) {
			if (n % i == 0) {
				path.push_back(i);
				dfs(n / i, path, ans, on);
				path.pop_back();
			}
		}
		if (n != on) {
			path.push_back(n);
			ans.push_back(path);
			path.pop_back();
		}
		return;
	}

    vector<vector<int>> getFactors(int n) {
		vector<vector<int>> ans;
		vector<int> path;
		int on = n;
		dfs(n, path, ans, n);
		return ans;
    }
};


