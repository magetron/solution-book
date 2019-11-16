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

	bool dfs (int cur, int end, vector<int>& path, vector<bool>& visited, vector<vector<int>>& adj) {
		visited[cur] = true;
		path.push_back(cur);
		if (cur == end) return true;
		for (int nn : adj[cur]) {
			if (!visited[nn]) {
				if (dfs(nn, end, path, visited, adj)) return true;
			}
		}
        path.pop_back();
		return false;
	}

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj(n, vector<int>());
		for (vector<int> pair : edges) {
			adj[pair[0]].push_back(pair[1]);
			adj[pair[1]].push_back(pair[0]);
		}
		int i = 0;
		int maxn = -1;
		vector<bool> visited(n, false);
		queue<int> q;
		q.push(i); visited[i] = true;
		int d = 0;
		while (!q.empty()) {
			int s = q.size();
			for (int j = 0; j < s; j++) {
				int node = q.front(); q.pop();
				maxn = node;
				for (int nn : adj[node]) if (!visited[nn]) {
					q.push(nn);
					visited[nn] =true;
				}
			}
			d++;
		}
		i = maxn;
		int maxm = -1;
		visited.assign(n, false);
		q.push(i); visited[i] = true;
	    d = 0;
		while (!q.empty()) {
			int s = q.size();
			for (int j = 0; j < s; j++) {
				int node = q.front(); q.pop();
				maxm = node;
				for (int nn : adj[node]) if (!visited[nn]) {
					q.push(nn);
					visited[nn] =true;
				}
			}
			d++;
		}
		vector<int> path;
		visited.assign(n, false);
		dfs(maxn, maxm, path, visited, adj);
        //for (auto p : path) cout << p << " "; cout << endl;
		if (path.size() & 1) 
            return {path[path.size() / 2]};
        else 
            return {path[path.size() / 2 - 1], path[path.size() / 2]};
		//cout << maxn << " " << maxm << endl;
	}
};



