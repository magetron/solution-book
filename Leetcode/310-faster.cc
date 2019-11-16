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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) return {0};
        vector<unordered_set<int>> adj(n, unordered_set<int>());
		for (vector<int> pair : edges) {
			adj[pair[0]].insert(pair[1]);
			adj[pair[1]].insert(pair[0]);
		}
		queue<int> q;
		for (int i = 0; i < n; i++) if (adj[i].size() == 1) q.push(i);
		int c = n;
		while (c > 2) {
			c -= q.size();
			int s = q.size();
			for (int i = 0; i < s; i++) {
				int n = q.front(); q.pop();
				for (auto it = adj[n].begin(); it != adj[n].end(); ) {
                    int nn = *it;
                    it = adj[n].erase(it);
                    adj[nn].erase(n);
                    if (adj[nn].size() == 1) q.push(nn);
                }
			}
		}
		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
    }
};

