#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) { }
};

static int fast_io = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
	int helper(TreeNode* root, int& ans) {
		if (!root) return 0;
		int l = helper(root -> left, ans);
		int r = helper(root -> right, ans);
		int ls = max(max(l + root -> val, r + root -> val), root -> val);
		ans = max(ans, max(ls, l + root -> val + r));
		return ls;
	}

    int maxPathSum(TreeNode* root) {
       	int ans = INT_MIN;
		helper(root, ans);
		return ans;
    }
};
