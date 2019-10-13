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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> ap(buildings.size() * 2);
		for (int i = 0; i < buildings.size(); i++) {
			ap[i * 2].first = buildings[i][0];
			ap[i * 2].second = buildings[i][2];
			ap[i * 2 + 1].first = buildings[i][1];
			ap[i * 2 + 1].second = - buildings[i][2];
		}
		sort(ap.begin(), ap.end(), [] (const pair<int, int>& a, const pair<int, int>& b) -> bool {
				return a.first < b.first || (a.first == b.first && a.second > b.second);	
				});
		//for (auto p : ap) cout << p.first << " " << p.second << endl;

		auto pq_cmp = [] (const pair<int, int>& a, const pair<int, int>& b) -> bool {
			return a.second < b.second || (a.second == b.second && a.first < b.first);
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pq_cmp)> pq(pq_cmp);
		unordered_map<int, int> removal;
		pq.push({0, 0});
		vector<vector<int>> ans;
		for (auto p : ap) {
			if (p.second > 0) {
				if (p.second > pq.top().second) {
					ans.push_back({p.first, p.second});
					pq.push(p);
				} else {
					pq.push(p);
				}
			} else {
				if (-p.second == pq.top().second) {
					pq.pop();
					while (removal.find(pq.top().second) != removal.end()) {
						removal[pq.top().second]--;
						if (removal[pq.top().second] == 0) removal.erase(pq.top().second);
						pq.pop();
					}
					if (pq.top().second < -p.second) ans.push_back({p.first, pq.top().second});
				} else {
					if (removal.find(-p.second) != removal.end()) removal[-p.second]++;
					else removal[-p.second] = 1;
				}
			}
		}
		return ans;
	}
};

int main () {
	Solution s;
	vector<vector<int>> b{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	auto ans = s.getSkyline(b);
	cout << "-----" << endl;
	for (auto as : ans) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}
