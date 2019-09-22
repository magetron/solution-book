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
	void helper(TreeNode* root, int cur, int& ans) {
		cur = cur * 10 + root -> val;
		if (!root -> left && !root -> right) {
			ans += cur;
			return;
		}
		if (root -> left) helper(root -> left, cur, ans);
		if (root -> right) helper(root -> right, cur, ans);
		cur /= 10;
	}

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
		int ans = 0;
		helper(root, 0, ans);
        return ans;
    }
};
