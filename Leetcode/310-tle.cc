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
		vector<vector<int>> adj(n, vector<int>());
		for (vector<int> pair : edges) {
			adj[pair[0]].push_back(pair[1]);
			adj[pair[1]].push_back(pair[0]);
		}
		int mind = INT_MAX;
		vector<int> ds(n);
		for (int i = 0; i < n; i++) {
			vector<bool> visited(n, false);
			queue<int> q;
			q.push(i); visited[i] = true;
			int d = 0;
			while (!q.empty()) {
				int s = q.size();
				for (int j = 0; j < s; j++) {
					int node = q.front(); q.pop();
					for (int nn : adj[node]) if (!visited[nn]) {
						q.push(nn);
						visited[nn] =true;
					}
				}
				d++;
			}
			ds[i] = d;
			mind = min(mind, d);
		}
		vector<int> ans;
		for (int i = 0; i < n; i++) if (ds[i] == mind) ans.push_back(i);
		return ans;
	}
};


int main () {
	//vector<vector<int>> edges{{1,0},{1,2},{1,3}};
	vector<vector<int>> edges{{0,3},{1,3},{2,3},{4,3},{5,4}};
	Solution s;
	auto ans = s.findMinHeightTrees(6, edges);
	for (auto i : ans) cout << i << " "; cout << endl;
	return 0;
}
