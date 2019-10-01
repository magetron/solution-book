#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	void dfs(TreeNode* root, int d, int& md, vector<int>& ans) {
		if (!root) return;
		if (d > md) {
			md = d;
			ans.push_back(root -> val);
		}
		dfs(root -> right, d + 1, md, ans);
		dfs(root -> left, d + 1, md, ans);
	}

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
		int md = -1;
		dfs(root, 0, md, ans);
		return ans;
    }
};

int main () {
	Solution s;
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	n1 -> left = n2;
	n2 -> right = n3;
	n3 -> left = n4;
	n1 -> right = n5;
	n5 -> right = n6;
	n6 -> left = n7;
	n6 -> right = n8;
	auto ans = s.rightSideView(n1);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
