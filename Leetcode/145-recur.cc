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

	void postorder(TreeNode* root, vector<int>& ans) {
		if (root == nullptr) return;
		postorder(root -> left, ans);
		postorder(root -> right, ans);
		ans.push_back(root -> val);
	}

    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> ans;
		postorder(root, ans);
		return ans;
    }
};

