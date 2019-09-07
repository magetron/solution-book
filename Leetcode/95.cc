#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void offset (TreeNode* root, int n) {
		if (root != NULL) {
			root -> val += n;
			offset(root -> left, n);
			offset(root -> right, n);
		} else return;
	}

	TreeNode* copy (TreeNode* root) {
		if (root == NULL) return NULL;
		TreeNode* n = new TreeNode(root -> val);
		n -> left = copy(root -> left);
		n -> right = copy(root -> right);
		return n;
	}

    vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>();
		vector<vector<TreeNode*>> dict(n + 1);
		dict[0] = vector<TreeNode*>{NULL};
		dict[1] = vector<TreeNode*>{new TreeNode(1)};
		if (n == 1) return dict[1];
		for (int i = 2; i <= n; i++) 
			for (int j = 1; j <= i; j++) {
				vector<TreeNode*> lts = dict[j - 1];
				vector<TreeNode*> rts = dict[i - j];
				for (auto lit = lts.begin(); lit != lts.end(); lit++)
					for (auto rit = rts.begin(); rit != rts.end(); rit++) {
						TreeNode* root = new TreeNode(j);
						root -> left = copy(*lit);
						root -> right = copy(*rit);
						offset(root -> right, j);
						dict[i].push_back(root);
					}
			}
		return dict[n];
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<TreeNode *> ns = s.generateTrees(3);
	for (auto it = ns.begin(); it != ns.end(); it++) 
		cout << (*it) -> val << endl;
	return 0;
}
