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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() == 0 || k == 0) return false;
		set<ll> s {4 * (ll)INT_MIN, nums[0], 4 * (ll)INT_MAX};
		for (int i = 1; i < nums.size(); i++) {
			//for (auto j : s) cout << j << " "; cout << endl;
            //cout << *s.lower_bound((ll)nums[i] - (ll)t) << endl;
            //cout << (ll)nums[i] << endl;
            //cout << (ll)nums[i] + (long)t << endl;
			if (*s.lower_bound((ll)nums[i] - (ll)t) <= (ll)nums[i]) return true;
			if (*s.lower_bound((ll)nums[i]) <= (ll)nums[i] + (ll)t) return true;
			s.insert(nums[i]);
			if (i >= k) s.erase(nums[i - k]);
		}
		return false;
    }
};
