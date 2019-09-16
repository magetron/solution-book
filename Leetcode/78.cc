#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

	void helper (vector<int>& n, int l, int k, vector<vector<int>>& ans, bool mid) {
		//for (auto i : n) cout << i << " ";
		//cout << endl;
		if (l == k) {
			ans.push_back(vector<int>(n.begin(), n.begin() + k));
			if (!mid) ans.push_back(vector<int>(n.begin() + k, n.end()));
			return;
		}
		for (int i = l; i < n.size(); i++) 
			if (l == 0 || n[i] > n[l - 1]) {
				swap(n[l], n[i]);
				helper(n, l + 1, k, ans, mid);
				swap(n[i], n[l]);
			}
	}
		
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
   		vector<vector<int>> ans;
		for (int i = 0; i <= nums.size() / 2; i++) 
			if (nums.size() % 2 == 0 && i == nums.size() / 2) helper(nums, 0, i, ans, true);
			else helper(nums, 0, i, ans, false);
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> nums {1,2,3,4};
	auto ans = s.subsets(nums);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}
