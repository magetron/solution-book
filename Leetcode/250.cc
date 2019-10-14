#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

	bool dfs (TreeNode* root, int& ans) {
		if (!root -> left && !root -> right) {
			ans++;
			return true;
		}
		if (root -> left && root -> right) {
			bool l = dfs(root -> left, ans);
			bool r = dfs(root -> right, ans);
			if (l && r && root -> val == root -> left -> val && root -> val == root -> right -> val) {
				ans++;
				return true;
			} else return false;
		}
		if (root -> left) {
			bool l = dfs(root -> left, ans);
			if (l && root -> val == root -> left -> val) {
				ans++;
				return true;
			} else return false;
		}
		if (root -> right) {
			bool r = dfs(root -> right, ans);
			if (r && root -> val == root -> right -> val) {
				ans++;
				return true;
			} else return false;
		}
		return false;
	}


    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
		int ans = 0;
		dfs(root, ans);
		return ans;
    }
};

