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
    void wiggleSort(vector<int>& nums) {
		vector<int> cpy(nums);
		sort(cpy.begin(), cpy.end());
		int j = cpy.size() - 1, i = cpy.size() / 2 + cpy.size() % 2 - 1;
		for (int k = 0; k < nums.size() / 2; k++) {
			nums[2 * k] = cpy[i--];
			nums[2 * k + 1] = cpy[j--];
		}
		if (nums.size() % 2 == 1) nums[nums.size() - 1] = cpy[i];
    }
};

