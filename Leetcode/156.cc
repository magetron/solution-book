#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode*& ans) {
		if (!root -> left && !root -> right) {
            ans = root;
            return root;
        }
		TreeNode* new_root = helper(root -> left, ans);
		new_root -> left = root -> right;
		new_root -> right = root;
        root -> left = nullptr;
        root -> right = nullptr;
		return root;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* ans;
        helper(root, ans);
        return ans;
    }
};



