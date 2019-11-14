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
		vector<vector<pair<bool, int>>> mp(m, vector<pair<bool, int>>(n, {false, -1}));
		vector<int> pre;
		for (auto pos : positions) {
			if (mp[pos[0]][pos[1]].first) {
				ans.push_back(ans.back());
				continue;
			}
			vector<int> landids;
			for (auto d : dir) {
				int x = pos[0] + d.first;
				int y = pos[1] + d.second;
				if (x >= 0 && x < m && y >= 0 && y < n && mp[x][y].first) landids.push_back(mp[x][y].second);
			}
			//cout << pos[0] << " " << pos[1] << endl;
			//for (int landid : landids) cout << landid << " "; cout << endl;
			if (landids.size() == 0) {
				pre.push_back(id);
				mp[pos[0]][pos[1]] = {true, id};
				id++;
			} else {
				mp[pos[0]][pos[1]] = {true, landids.back()};
				int x = find(landids.back(), pre); landids.pop_back();
				for (int landid : landids) {
					int y = find(landid, pre);
					pre[y] = x;
				}
			}
			int cnt = 0;
			for (int i = 0; i < pre.size(); i++) if (pre[i] == i) cnt++;
			ans.push_back(cnt);
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


