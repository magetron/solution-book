#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

struct hashfunc {
	size_t operator () (const pair<int, int>& p) const {
		return ((p.first & ~100007) | (p.second & 100007)) ^ ((p.first & 100007) | (p.second & ~100007)); 
	}
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
		if (points.size() <= 2) return points.size();
		int ans = 0;
		for (int i = 0; i < points.size() - 1; i++) {
			unordered_map<pair<int, int>, int, hashfunc> dict;
			int overlap = 0, vertical = 0, horizontal = 0;
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) overlap++;
				else {
					int a = (points[i][1] - points[j][1]);
					int b = (points[i][0] - points[j][0]);
					//cout << a << " " << b << endl;
					if (a == 0) {
						horizontal++;
						continue;
					} else if (b == 0) {
						vertical++;
						continue;
					}
					int g = gcd(a, b);
					a /= g;
					b /= g;
					if (a < 0) { a = -a; b = -b; }
					dict[make_pair(a, b)]++;
				}
			}
			//cout << "i = " << i << endl;
			for (auto p : dict) {
				//cout << p.first.first << " " << p.first.second << " "<< p.second << endl;
				//cout << overlap << endl;
				ans = max(ans, p.second + overlap + 1);
			}
			//cout << ans << endl;
			ans = max(max(ans, vertical + overlap + 1), horizontal + overlap + 1);
		}
		return ans;		
    }
};

int main () {
	Solution s;
	//vector<vector<int>> points{{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
	vector<vector<int>> points{{2,3}, {3,3}, {-5,3}};
	cout << s.maxPoints(points) << endl;
	return 0;
}
