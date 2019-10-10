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

	int inorder(TreeNode* root, int& k) {
		if (!root) return INT_MIN;
		int res = inorder(root -> left, k);
		if (res != INT_MIN) return res;
		if (k == 0) return root -> val; else k--;
		return inorder(root -> right, k);
	}

    int kthSmallest(TreeNode* root, int K) {
		int k = K - 1;
		return inorder(root, k);
    }
};

