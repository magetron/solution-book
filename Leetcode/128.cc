#include <bits/stdc++.h>
#pragma optimize GCC ("Ofast");

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
	public :
		
		int find(unordered_map<int, pair<int, int>>& pre, int k) {
			int y = k;
			while (pre[k].first != k) k = pre[k].first;
			while (pre[y].first != k) {
				int yy = pre[y].first;
				pre[y].first = k;
				y = yy;
			}
			return k;
		}

		void unite(unordered_map<int, pair<int, int>>& pre, int a, int b) {
			int ap = find(pre, a);
			int bp = find(pre, b);
			if (ap != bp) {
				pre[bp].first = ap;
				pre[ap].second += pre[bp].second;
			}
		}

		int longestConsecutive(vector<int>& nums) {
			unordered_map<int, pair<int, int>> pre;
			for (int i : nums) {
				auto found = pre.find(i);
				if (found == pre.end()) pre[i] = {i, 1};
			}
			for (int i : nums) {
				auto found1 = pre.find(i - 1);
				auto found2 = pre.find(i + 1);
				if (found1 != pre.end()) unite(pre, i, i - 1);
				if (found2 != pre.end()) unite(pre, i, i + 1);
			}
			int ans = 0;
			for (auto p : pre) if (p.first == p.second.first) ans = max(ans, p.second.second);
			return ans;
		}
};	



