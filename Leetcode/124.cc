#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) { }
};

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


class Solution {
	public:
		int helper (TreeNode* root, int& ans) {
			if (root == nullptr) return node(INT_MIN, 0);
			int l_node = helper(root -> left);
			int r_node = helper(root -> right);
			int ls = max(max(l_node + root -> val, r_node + root -> val), root -> val);
			ans = max(max(ls, ans), l_node + r_node + root -> val);
			return ls;
		}

		int maxPathSum (TreeNode* root) {
			int ans = INT_MIN;;
			helper(root, ans);
			return ans;
		}
};
