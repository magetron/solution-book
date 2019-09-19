#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
		if (root == NULL) return;
		if (root -> left == NULL && root -> right == NULL) return;
		if (root -> left != NULL) flatten(root -> left);
		if (root -> right != NULL) flatten(root -> right);
		if (root -> left != NULL && root -> right != NULL) {
			TreeNode* prev;
			TreeNode* cur = root -> left;
			while (cur) {
				prev = cur;
				cur = cur -> right;
			}
			prev -> right = root -> right;
			root -> right = root -> left;
			root -> left = NULL;
		} else if (root -> left != NULL) {
			root -> right = root -> left;
			root -> left = NULL;
		}
    }
};
