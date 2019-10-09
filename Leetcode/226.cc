#include<bits/stdc++.h>
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
    TreeNode* invertTree(TreeNode* root) {
		if (!root) return nullptr;
		swap(root -> left, root -> right);
		invertTree(root -> left);
		invertTree(root -> right);
		return root;
    }
};

