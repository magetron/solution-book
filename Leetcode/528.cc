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

	vector<int> ps;

    Solution(vector<int>& w) {
		ps = vector<int>(w.size());
		int s = 0;
		for (int i = 0; i < w.size(); i++) {
			s += w[i];
			ps[i] = s;
		}
	}
    
    int pickIndex() {
		int ma = ps.back();
		int r = rand() % ma;
		auto it = upper_bound(ps.begin(), ps.end(), r);
		return it - ps.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
