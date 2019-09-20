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

struct node {
	int cur_sum;
	int line_sum;
	node (int cs, int ls) : cur_sum(cs), line_sum(ls) { }
};

class Solution {
	public:
		node helper (TreeNode* root) {
			if (root == nullptr) return node(INT_MIN, 0);
			node l_node = helper(root -> left);
			node r_node = helper(root -> right);
			int ls = max(max(l_node.line_sum + root -> val, r_node.line_sum + root -> val), root -> val);
			int cs = max(max(ls, l_node.line_sum + root -> val + r_node.line_sum), max(l_node.cur_sum, r_node.cur_sum));
			return node(cs, ls);
		}

		int maxPathSum (TreeNode* root) {
			node ans = helper(root);
			return ans.cur_sum;
		}
};