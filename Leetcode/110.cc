#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info {
	bool balance;
	int depth;
	Info(bool b, int d) : balance(b), depth(d) { }
};

class Solution {
public:

	Info dfs(TreeNode* root) {
		if (root == NULL) return Info(true, 0);
		Info l = dfs(root -> left);
		if (!l.balance) return Info(false, -1);
		Info r = dfs(root -> right);
		if (!r.balance) return Info(false, -1);
		if (abs(l.depth - r.depth) > 1) return Info(false, -1);
		return Info(true, max(l.depth, r.depth) + 1);
	}


	bool isBalanced(TreeNode* root) {
    	return dfs(root).balance;    
    }

};
