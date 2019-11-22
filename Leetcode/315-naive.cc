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
    vector<int> countSmaller(vector<int>& nums) {
		if (nums.size() == 0) return {};
		vector<int> ans;
		for (int i = 0; i < nums.size() - 1; i++) {
			int c = 0;
			for (int j = i + 1; j < nums.size(); j++) if (nums[j] < nums[i]) c++;
			ans.emplace_back(c);
		}
		ans.push_back(0);
		return ans;
    }
};
