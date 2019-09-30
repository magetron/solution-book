#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int __ = [] () {
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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr, *second = nullptr;
        while (root) {
            if (!root -> left) {
                if (!prev || prev -> val > root -> val) {
                    if (!first) first = prev;
                    if (first) second = root;
                }
                prev = root;
                root = root -> right;
            } else {
                TreeNode* p = root -> left;
                while (p -> right && p -> right != root) p = p -> right;
                if (!p -> right) {
                    p -> right = root;
                    root = root -> left;
                } else {
                    p -> right = nullptr;
                    if (!prev || prev -> val > root -> val) {
                        if (!first) first = prev;
                        if (first) second = root;
                    }
                    prev = root;
                    root = root -> right;
                }
            }
        }
        swap(first -> val, second -> val);
    }
};
