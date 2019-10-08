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
    
    inline int get_id (long n, long t) {
        return n >= 0 ? n / (t + 1) : (n + 1) / (t + 1) - 1;
    }
    
   	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k == 0 || nums.size() == 0) return false;
		unordered_map<int, long> dict;
		for (int i = 0; i < nums.size(); i++) {
			int id = get_id(nums[i], t);
			if (dict.find(id) != dict.end()) return true;
			if (dict.find(id - 1) != dict.end() && nums[i] - dict[id - 1] <= t) return true;
			if (dict.find(id + 1) != dict.end() && dict[id + 1] - nums[i] <= t) return true;
			dict[id] = nums[i];
			if (i >= k) dict.erase(get_id(nums[i - k], t));
		}
		return false;
    }
};

