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

    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
		vector<int> ans;
    	queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front(); q.pop();
				if (i == 0) ans.push_back(t -> val);
				if (t -> right) q.push(t -> right);
				if (t -> left) q.push(t -> left);
			}
		}
		return ans;
	}

};
