#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> pre;

	int find (int x) {
		int r = x;
		while (pre[r] != r) r = pre[r];
		// compression
		int i = x, j;
		while (i != r) {
			j = pre[i];
			pre[i] = r;
			i = j;
		}
		return r;
	}

	void join (int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if (fx != fy) pre[fx] = fy;
	}

    int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		pre = vector<int>(n);
		for (int i = 0; i < n; i++) pre[i] = i;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (M[i][j]) join(i, j);
		int ans = 0;
		for (int i = 0; i < n; i++) if (pre[i] == i) ans++;
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;

	return 0;
}
