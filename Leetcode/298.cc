#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

	void preorder(TreeNode* root, TreeNode* prev, int c, int& ans) {
		if (!root) return;
		if (!prev || prev -> val + 1 != root -> val) {
			ans = max(ans, 1);
			preorder(root -> left, root, 1, ans);
			preorder(root -> right, root, 1, ans);
		} else {
			ans = max(ans, c + 1);
			preorder(root -> left, root, c + 1, ans);
			preorder(root -> right, root, c + 1, ans);
		}
	}

    int longestConsecutive(TreeNode* root) {
		int ans = 0;
		preorder(root, nullptr, 0, ans);
		return ans;
    }
};

