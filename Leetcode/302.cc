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
		int l = 0, r = y + 1;
		int lp = -1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			bool found = false;
			for (int i = 0; i < m; i++) if (image[i][mid] == '1') {
				lp = mid;
				found = true;
				break;
			}
			if (!found) l = mid + 1;
			else r = mid;
		}
		l = y, r = n;
		int rp = -1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			bool found = false;
			for (int i = 0; i < m; i++) if (image[i][mid] == '1') {
				rp = mid;
				found = true;
				break;
			}
			if (!found) r = mid;
			else l = mid + 1;
		}
		l = 0, r = x + 1;
		int up = -1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			bool found = false;
			for (int i = 0; i < n; i++) if (image[mid][i] == '1') {
				up = mid;
				found = true;
				break;
			}
			if (!found) l = mid + 1;
			else r = mid;
		}
		l = x, r = m;
		int dp = -1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			bool found = false;
			for (int i = 0; i < n; i++) if (image[mid][i] == '1') {
				dp = mid;
				found = true;
				break;
			}
			if (!found) r = mid;
			else l = mid + 1;
		}
		//cout << up << " " << dp << " " << lp << " " << rp << endl;
		return (dp - up + 1) * (rp - lp + 1);
    }
};

