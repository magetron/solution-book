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
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        int i = 0;
		int j = 0;
		int su = nums[0];
		int ans = nums.size() + 1;
		while (j < nums.size()) {
            //cout << su << endl;
			if (su >= s) {
				while (i <= j && su >= s) {
					su -= nums[i];
					i++;
				}
				i--; su += nums[i];
                ans = min(ans, j - i + 1);
                su -= nums[i]; i++;
			}
			if (j == nums.size() - 1) break;
            j++; su += nums[j];
		}
		return (ans == nums.size() + 1 ? 0 : ans);
    }
};

