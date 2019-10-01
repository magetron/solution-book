#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void inorder(TreeNode* root, vector<TreeNode*>& res) {
		if (root == NULL) return;
		inorder(root -> left, res);
		res.push_back(root);
		inorder(root -> right, res);
	}

    void recoverTree(TreeNode* root) {
		vector<TreeNode*> res;
		inorder(root, res);
		int wrong_pos = -1;
		for (int i = 1; i < res.size(); i++) if (res[i] -> val <= res[i - 1] -> val) {
			wrong_pos = i - 1;
			break;
		}
		if (wrong_pos == -1) return;
		for (int i = wrong_pos + 1; i <= res.size(); i++) if (i == res.size() || res[i] -> val > res[wrong_pos] -> val) {
			swap(res[i - 1] -> val, res[wrong_pos] -> val);
			break;
		}
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1 -> left = n3;
	n3 -> right = n2;
	Solution s;
	s.recoverTree(n1);
	cout << n1 -> val << " " << n1 -> left -> val << " " << n1 -> left -> right -> val << endl;
	return 0;
}
