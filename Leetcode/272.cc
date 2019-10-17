i#include<bits/stdc++.h>
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

	void inorder (TreeNode* root, vector<int>& ans) {
		if (!root) return;
		inorder(root -> left, ans);
		ans.push_back(root -> val);
		inorder(root -> right, ans);
	}

    vector<int> closestKValues(TreeNode* root, double target, int k) {
		vector<int> ans;
		inorder(root, ans);
		vector<int> ret;
		if (target < ans[0]) {
			vector<int> cpy(ans.begin(), ans.begin() + k);
			return cpy;
		}
		if (target > ans.back()) {
			vector<int> cpy(ans.end() - k, ans.end());
			return cpy;
		}
    	for (int i = 0; i < ans.size() - 1; i++) 
			if (ans[i] <= target && ans[i + 1] >= target) {
				int r = i + 1;
				int l = i;
				while (r - l - 1 < k) {
					if (l >= 0 && abs(ans[r] - target) > abs(ans[l] - target)) l--;
					else r++;
				}
				vector<int> cpy(ans.begin() + l + 1, ans.begin() + r);
				return cpy;
				break;
			}
		return {};
	}
};

