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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> dict(nums2.begin(), nums2.end());
		unordered_set<int> ans;
		for (int i = 0; i < nums1.size(); i++) {
			if (dict.find(nums1[i]) != dict.end()) ans.insert(nums1[i]);
		}
		vector<int> ret;
		for (auto i : ans) ret.push_back(i);
		return ret;
    }
};
