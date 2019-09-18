#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	inline bool inRange(int val, long l, long r) {
		return (val > l && val < r);
	}

	bool helper(TreeNode* root, long l, long r) {
		if (!inRange(root -> val, l, r)) return false;
		return (root -> left == NULL ? true : helper(root -> left, l, root -> val)) && (root -> right == NULL ? true : helper(root -> right, root -> val, r));
	}

    bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		return helper(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};
