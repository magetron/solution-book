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

	inline int find (int x, vector<int>& pre) {
		int y = x;
		while (pre[x] != x) x = pre[x];
		while (pre[y] != x) {
			int tmp = pre[y];
			pre[y] = x;
			y = tmp;
		}
		return x;
	}

    bool validTree(int n, vector<vector<int>>& edges) {
		vector<int> pre(n);
		for (int i = 0; i < n; i++) pre[i] = i;
		for (auto p : edges) {
    		int x = find(p[0], pre);
			int y = find(p[1], pre);
			if (x == y) return false; else pre[y] = x;
		}
		int c = 0;
		for (int i = 0; i < n; i++) if (pre[i] == i) c++;
		return c == 1;
	}
};

