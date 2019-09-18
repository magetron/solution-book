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
    vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return vector<vector<int>>();
		queue<TreeNode *> q;
		q.push(root);
		int count = 1;
		vector<vector<int>> ans;
		while (count) {
			vector<int> lvl;
			int new_count = 0;
			for (int i = 0; i < count; i++) {
				TreeNode *cur = q.front();
				q.pop();
				if (cur -> left != NULL) {
					q.push(cur -> left);
					new_count++;
				}
				if (cur -> right != NULL) {
					q.push(cur -> right);
					new_count++;
				}
				lvl.push_back(cur -> val);
			}
			ans.push_back(lvl);
			count = new_count;
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	TreeNode *n1 = new TreeNode(3);
	TreeNode *n2 = new TreeNode(9);
	TreeNode *n3 = new TreeNode(20);
	TreeNode *n4 = new TreeNode(15);
	TreeNode *n5 = new TreeNode(7);
	n1 -> left = n2;
	n1 -> right = n3;
	n3 -> left = n4;
	n3 -> right = n5;
		
	Solution s;
	auto ans = s.levelOrder(n1);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}

	return 0;
}
