#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	TreeNode* dfs(vector<int>& preorder, int i, vector<int>& inorder, int l, int r) {
		if (i >= preorder.size()) return NULL;
		TreeNode* root = new TreeNode(preorder[i]);
		int pos = -1;
		for (int j = l; j < r; j++) if (inorder[j] == preorder[i]) { pos = j; break; }
		if (pos == -1) return NULL;
		root -> left = dfs(preorder, i + 1, inorder, l, pos);
		root -> right = dfs(preorder, i + pos - l + 1, inorder, pos + 1, r);
		return root;
	}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return dfs(preorder, 0, inorder, 0, inorder.size());
    }
};