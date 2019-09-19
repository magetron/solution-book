#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

	int helper (TreeNode* root) {
		if (root -> left == NULL && root -> right == NULL) return 1;
		int left = INT_MAX, right = INT_MAX;
		if (root -> left) left = helper(root -> left);
		if (root -> right) right = helper(root -> right);
		return 1 + min(left, right);
	}
		
    int minDepth(TreeNode* root) {
		return (root ? helper(root) : 0);
    }

};
