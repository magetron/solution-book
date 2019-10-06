#include<bits/stdc++.h>
#define ll long long
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
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();        
		int ans = 2;
    	for (int i = 1; i < points.size(); i++) {
			int x1 = points[i][0];
			int y1 = points[i][1];
			int x0 = points[i - 1][0];
			int y0 = points[i - 1][1];
			int count = 0;
			if (x1 == x0 && y1 == y0)
				for (int j = 0; j < points.size(); j++) {
					int x2 = points[j][0];
					int y2 = points[j][1];
					if (x1 == x2 && y1 == y2) count++;
				}
			else 
				for (int j = 0; j < points.size(); j++) {
					int x2 = points[j][0];
					int y2 = points[j][1];
					if ((ll)(x1 - x0) * (ll)(y2 - y1) == (ll)(x2 - x1) * (ll)(y1 - y0)) count++;
				}
			ans = max(ans, count);
		}
		return ans;
	}

};

