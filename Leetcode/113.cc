#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans) {
		if (root == NULL) return;
		if (root -> left == NULL && root -> right == NULL && root -> val == sum) {
			path.push_back(root -> val);
			ans.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root -> val);
		helper(root -> left, sum, path, ans);
		helper(root -> right, sum, path, ans);
		path.pop_back();


			
	}	

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		vector<int> path;
		helper(root, sum, path, ans);
		return ans;
    }
};
