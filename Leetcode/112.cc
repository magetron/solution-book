#include <bits/stdc++.h>
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
    	if (root -> left == nullptr && root -> right == nullptr) return root -> val == sum;
		else return (root -> left == nullptr ? false : hasPathSum(root -> left, sum - root -> val)) ||
					(root -> right == nullptr ? false : hasPathSum(root -> right, sum - root -> val));
    }
};
