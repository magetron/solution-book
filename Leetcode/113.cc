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
	void helper (TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans) {
		path.push_back(root -> val);
		if (root -> left == nullptr && root -> right == nullptr && root -> val == sum) {
			ans.push_back(path);
            path.pop_back();
			return;
		}
		if (root -> left != nullptr) helper(root -> left, sum - root -> val, path, ans);
		if (root -> right != nullptr) helper(root -> right, sum - root -> val, path, ans);
		path.pop_back();
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr) return vector<vector<int>>();
		vector<int> path;
		vector<vector<int>> ans;
		helper(root, sum, path, ans);
		return ans;
    }
};
