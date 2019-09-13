#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:

    inline bool check (vector<int>& l, vector<int>& r) {
        return l[1] >= r[0];
    }

    void merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) { return l[0] > r[0]; });
        int i = intervals.size() - 1;
        while (i > 0) {
            bool mergable = check(intervals[i], intervals[i - 1]);
            if (mergable) {
                vector<int> new_interval{min(intervals[i][0], intervals[i - 1][0]), max(intervals[i][1], intervals[i - 1][1])};
                intervals.erase(intervals.begin() + i);
                intervals.erase(intervals.begin() + i - 1);
                intervals.insert(intervals.begin() + i - 1, new_interval);
            }
            i--;
        }
    }

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		reverse(intervals.begin(), intervals.end());
		auto it = intervals.begin();
		for (; it != intervals.end(); it++) if (newInterval[0] > (*it)[0]) {
			intervals.insert(it, newInterval);
			break;
		}
		if (it == intervals.end()) intervals.insert(it, newInterval);
		//for (auto it = intervals.begin(); it != intervals.end(); it++) cout << (*it)[0] << " " << (*it)[1] << endl;
		merge(intervals);
        reverse(intervals.begin(), intervals.end());
		return intervals;
	}
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	/*vector<int> p1{1, 2};
	vector<int> p2{3, 5};
	vector<int> p3{6, 7};
	vector<int> p4{8, 10};
	vector<int> p5{12, 16};
	vector<vector<int>> intvs{p1, p2, p3, p4, p5};*/
	vector<vector<int>> empty;
	vector<int> new_intv{4, 8};
	auto ans = s.insert(empty, new_intv);
	for (auto p : ans) cout << p[0] << " " << p[1] << endl;
	return 0;
}

