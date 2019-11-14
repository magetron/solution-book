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
	vector<pair<int, int>> dir{{0,1},{0,-1},{-1,0},{1,0}};

	int find (int x, vector<int>& pre) {
		int cpy = x;
		while (x != pre[x]) x = pre[x];
		while (cpy != x) {
			int tmp = pre[cpy];
			pre[cpy] = x;
			cpy = tmp;
		}
		return x;
	}

	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		if (!m || !n) return {};
		int id = 0;
		vector<int> ans;
		vector<vector<int>> mp(m, vector<int>(n, -1));
		vector<int> pre;
		int c = 0;
		for (auto pos : positions) {
			if (mp[pos[0]][pos[1]] != -1) {
				ans.push_back(ans.back());
				continue;
			}
			vector<int> landids;
			for (auto d : dir) {
				int x = pos[0] + d.first;
				int y = pos[1] + d.second;
				if (x >= 0 && x < m && y >= 0 && y < n && mp[x][y] != -1) landids.push_back(mp[x][y]);
			}
			//cout << pos[0] << " " << pos[1] << endl;
			//for (int landid : landids) cout << landid << " "; cout << endl;
			if (landids.size() == 0) {
				pre.push_back(id);
				mp[pos[0]][pos[1]] = id;
				id++;
				c++;
			} else {
				mp[pos[0]][pos[1]] = landids.back();
				int x = find(landids.back(), pre); landids.pop_back();
				for (int landid : landids) {
					int y = find(landid, pre);
					if (y != x) {
						pre[y] = x;
						c--;
					}
				}
			}
			ans.push_back(c);
		}
		return ans;
    }
};

int main () {
	vector<vector<int>> poss{{0,0},{1,1},{0,1},{1,0}};
	Solution s;
	auto ans = s.numIslands2(2, 2, poss);
	for (int i : ans) cout << i << " "; cout << endl;
	return 0;
}


