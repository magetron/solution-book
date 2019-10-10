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
    vector<string> summaryRanges(vector<int>& nums) {
    	int i = 0;
		vector<string> ans;
		while (i < nums.size()) {
			if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) ans.push_back(to_string(nums[i]));
			else {
				int j = i + 1;
				while (j < nums.size() - 1 && nums[j + 1] == nums[j] + 1) j++;
				string s = to_string(nums[i]) + "->" + to_string(nums[j]);
				ans.push_back(s);
				i = j;
			}
			i++;
		}
		return ans;
    }
};

int main () {
	Solution s;
	vector<int> n{0,2,3,4,7,8,9,10,11,18,20,21};
	auto ans = s.summaryRanges(n);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
