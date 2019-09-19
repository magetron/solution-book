#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

	int helper (TreeNode* root, int limit) {
		if (root -> left == NULL && root -> right == NULL) return 1;
		if (limit < 0) return INT_MAX;
		int left = INT_MAX, right = INT_MAX;
		if (root -> left) left = helper(root -> left, limit - 1);
		if (root -> right) right = helper(root -> right, left - 1);
        if (min(left, right) == INT_MAX) return INT_MAX;
		return 1 + min(left, right);
	}
		
    int minDepth(TreeNode* root) {
		return (root ? helper(root, INT_MAX) : 0);
    }

};
