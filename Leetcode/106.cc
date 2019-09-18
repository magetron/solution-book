 #include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	void helper (vector<int>& inorder, int l, int r, vector<int>& postorder, int i) {
		if (i < 0) return NULL;
		TreeNode* root = new TreeNode(postorder[i]);
		int pos = -1;
		for (int j = l; j < r; j++) if (inorder[j] == postorder[i]) { pos = j; break; }
		if (pos == -1) return NULL;
		root -> right = helper(inorder, pos + 1, r, postorder, i - 1);
		root -> left = helper(inorder, l, pos, postorder, i - (r - pos));
		return root;
	}


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, postorder.size() - 1);
    }
};

