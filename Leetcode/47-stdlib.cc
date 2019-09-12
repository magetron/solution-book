#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
  		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		do {
			ans.push_back(nums);
		} while(next_permutation(nums.begin(), nums.end()));
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{1,2,1};
	auto ans = s.permuteUnique(nums);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}

