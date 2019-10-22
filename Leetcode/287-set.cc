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
    int findDuplicate(vector<int>& nums) {
		unordered_set<int> dict;
		for (auto n : nums) {
			if (dict.find(n) != dict.end()) return n;
			else dict.insert(n);
		}
		return -1;
    }
};
