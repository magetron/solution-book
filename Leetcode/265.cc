#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
		 int m = costs.size();
		 if (!m) return 0;
		 int n = costs[0].size();
		 if (!n) return 0;
		 if (m == 1) return *min_element(costs[0].begin(), costs[0].end());
		 int min = INT_MAX, min2 = INT_MAX;
		 int minpos = -1, min2pos = -1;
		 for (int i = 0; i < n; i++) if (costs[0][i] < min) {
			 min2 = min;
			 min2pos = minpos;
			 min = costs[0][i];
			 minpos = i;
		 } else if (costs[0][i] < min2) {
			 min2 = costs[0][i];
			 min2pos = i;
		 }
		 int nmin = INT_MAX, nmin2 = INT_MAX;
		 int nminpos = -1, nmin2pos = -1;
		 for (int i = 1; i < m; i++) { 
			for (int j = 0; j < n; j++) {
				int nres = -1;
				if (j == minpos) nres = min2 + costs[i][j];
				else nres = min + costs[i][j];
				if (nres < nmin) {
					nmin2 = nmin;
					nmin2pos = nminpos;
					nmin = nres;
					nminpos = j;
				} else if (nres < nmin2) {
					nmin2 = nres;
					nmin2pos = j;
				}
			}
			min = nmin;
			minpos = nminpos;
			min2 = nmin2;
			min2pos = nmin2pos;
			nmin = INT_MAX;
			nmin2 = INT_MAX;
			nminpos = -1;
			nmin2pos = -1;
		 }
		 return min;
	}
};

int main () {
	Solution s;
	vector<vector<int>> cs{{20,19,11,13,12,16,16,17,15,9,5,18},{3,8,15,17,19,8,18,3,11,6,7,12},{15,4,11,1,18,2,10,9,3,6,4,15}};
	cout << s.minCostII(cs) << endl;
	return 0;
}
