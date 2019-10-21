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

	TreeNode* inorder (TreeNode* root, TreeNode* p, bool& vp) {
		if (!root) return nullptr;
		TreeNode *l = inorder(root -> left, p, vp);
		if (l) return l;
		if (vp) return root;
		if (root == p) vp = true;
		TreeNode *r = inorder(root -> right, p, vp);
		if (r) return r;
		return nullptr;
	}

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		bool vp = false;
		return inorder(root, p, vp);
    }
};

