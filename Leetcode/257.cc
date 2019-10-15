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

	void dfs (TreeNode* root, string& path, vector<string>& ans) {
		if (!root) return;
		string news = "->" + to_string(root -> val);
        path += news;
		if (!root -> left && !root -> right) ans.push_back(path);
		else {
			if (root -> left) dfs(root -> left, path, ans);
			if (root -> right) dfs(root -> right, path, ans);
		}
        path.erase(path.length() - news.length(), news.length());
		return;
	}

    vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return {};
		string path = to_string(root -> val);
        if (!root -> left && !root -> right) {
            return {path};
        }
		vector<string> ans;
		if (root -> left) dfs(root -> left, path, ans);
		if (root -> right) dfs(root -> right, path, ans);
		return ans;
    }
};

