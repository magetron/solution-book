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
class BSTIterator {
public:
    vector<int> arr;
	int pointer = 0;

	void helper (TreeNode* root, vector<int>& arr) {
		if (!root) return;
		helper(root -> left, arr);
		arr.push_back(root -> val);
		helper(root -> right, arr);
	}

	BSTIterator(TreeNode* root) {
		helper(root, arr);
		pointer = 0;
    }

    /** @return the next smallest number */
    int next() {
		return arr[pointer++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return pointer < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
