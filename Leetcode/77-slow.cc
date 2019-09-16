#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

	void helper (vector<int>& n, int l, int k, vector<vector<int>>& ans) {
		//for (auto i : n) cout << i << " ";
		//cout << endl;
		if (l == k) {
			ans.push_back(vector<int>(n.begin(), n.begin() + k));
			return;
		}
		for (int i = l; i < n.size(); i++) 
			if (l == 0 || n[i] > n[l - 1]) {
				swap(n[l], n[i]);
				helper(n, l + 1, k, ans);
				swap(n[i], n[l]);
			}
	}
		
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> nums(n);
		for (int i = 1; i <= n; i++) nums[i - 1]= i;
		helper(nums, 0, k, ans);
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	auto ans = s.combine(4, 2);
	for (auto as : ans) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}
