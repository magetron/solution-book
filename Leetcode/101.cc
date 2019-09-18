#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
	bool isSymmetricHelper(TreeNode* p, TreeNode* q) {
       	if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;
    	if (p -> val != q -> val) return false;
		return isSymmetricHelper(p -> left, q -> right) && isSymmetricHelper(p -> right, q -> left); 
    }

	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		if (root -> left == NULL && root -> right == NULL) return true;
		if (root -> left == NULL || root -> right == NULL) return false;
		return isSymmetricHelper(root -> left, root -> right);
	}

};
