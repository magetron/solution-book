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
		if (nums.size() == 0) return;
		for (int i = 0; i < nums.size() - 1; i++)
			if (i % 2 == 0 && nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
			else if (i % 2 == 1 && nums[i] < nums[i + 1]) swap(nums[i], nums[i + 1]);
		//for (auto i : nums) cout << i << " "; cout << endl;
    }
};

