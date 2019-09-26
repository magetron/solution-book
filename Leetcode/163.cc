#include <bits/stdc++.h>
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
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ans;
		if (nums.size() == 0) {
			if (upper > lower) ans.push_back(to_string(lower) + "->" + to_string(upper));
			else ans.push_back(to_string(upper));
			return ans;
		}
		int l = 0;
		while (nums[l] < lower) l++;
		int r = nums.size() - 1;
		while (nums[r] > upper) r--;
		if (nums[l] > lower) {
			if (nums[l] == lower + 1) ans.push_back(to_string(lower));
			else ans.push_back(to_string(lower) + "->" + to_string(nums[l] - 1));
		}
		for (int i = l; i < r; i++) 
			if ((long)nums[i + 1] > (long)nums[i] + 1) {
				if ((long)nums[i + 1] == (long)nums[i] + 2) ans.push_back(to_string(nums[i] + 1));
				else ans.push_back(to_string(nums[i] + 1) + "->" + to_string(nums[i + 1] - 1));
			}
		if (upper > nums[r]) {
			if (upper == nums[r] + 1) ans.push_back(to_string(upper));
			else ans.push_back(to_string(nums[r] + 1) + "->" + to_string(upper));
		}

		return ans;
    }
};

int main () {
	Solution s;
	vector<int> n;
	auto ans = s.findMissingRanges(n, 0, 99);
	for (auto str : ans) cout << str << " ";
	cout << endl;
	return 0;
}
