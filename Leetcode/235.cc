#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	int find(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
		if (!root) return 0;
		int l = find(root -> left, p, q, ans);
		int r = find(root -> right, p, q, ans);
		if (l == 3 || r == 3) return 3;
		if (l == 0 && r == 0) {
			if (root == p) return 1;
			else if (root == q) return 2;
			else return 0;
		} else {
			if ((l + r == 3) || (l == 1 && root == q) || (r == 1 && root == q) || (l == 2 && root == p) || (r == 2 && root == p)) {
				ans = root;
				return 3;
			} else return max(l, r);
		}
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p -> val > q -> val) swap(p, q);
		TreeNode* ans;
		find(root, p, q, ans);
		return ans;
    }
};

