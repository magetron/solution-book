#include<bits/stdc++.h>
#pragma GCC optimze ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
		int j = 1;
		while (j < nums.size()) {
			if (nums[j] != nums[i]) nums[++i] = nums[j];
			j++;
        }
        return i + 1;
    }
};
