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
    int minArea(vector<vector<char>>& image, int x, int y) {
		int m = image.size();
        if (!m) return 0;
        int n = image[0].size();
        if (!n) return 0;
        int u = INT_MAX, d = 0;
		int l = INT_MAX, r = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (image[i][j] == '1') {
                //cout << i << " " << j << endl;
				u = min(u, i);
				d = max(d, i);
				l = min(l, j);
				r = max(r, j);
		}
        //cout << u << " " << d << " " << l << " " << r << endl;
		return (d - u + 1) * (r - l + 1);
    }
};

