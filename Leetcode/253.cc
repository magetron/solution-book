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
    int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> tp(intervals.size() * 2);
		for (int i = 0; i < intervals.size(); i++) {
			tp[2 * i] = intervals[i][0];
			tp[2 * i + 1] = -intervals[i][1];
		}
		sort(tp.begin(), tp.end(), [] (const int& a, const int& b) -> bool {
				return abs(a) < abs(b) || (abs(a) == abs(b) && a < b);
				});
		//for (auto i : tp) cout << i << " ";  cout << endl;
		int ans = 0;
		int r = 0;
		for (int i = 0; i < tp.size(); i++) if (tp[i] >= 0) {
			r++;
			ans = max(ans, r);
		} else r--;
		return ans;
    }
};

int main () {
	Solution s;
	vector<vector<int>> i{{0,30}, {5,10}, {15,20}};
	cout << s.minMeetingRooms(i) << endl;
	return 0;
}
