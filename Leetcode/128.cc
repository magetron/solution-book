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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict(nums.begin(), nums.end());
		int ans = 0;
		for (int i : nums) 
			if (dict.count(i)) {
				dict.erase(i);
				int prev = i - 1;
				int succ = i + 1;
				while (dict.count(prev)) {
					dict.erase(prev);
					prev--;
				}
				while (dict.count(succ)) {
					dict.erase(succ);
					succ++;
				}
				ans = max(ans, succ - prev - 1);
			}
		return ans;
    }
};

