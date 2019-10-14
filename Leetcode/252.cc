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
    bool canAttendMeetings(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) return true;
		sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) -> bool {
				return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
				});
        //for (auto i : intervals) cout << i[0] << " " << i[1] << endl;
 		for (int i = 0; i < intervals.size() - 1; i++) {
			if (intervals[i][1] > intervals[i + 1][0]) return false;
		}
		return true;
    }
};

