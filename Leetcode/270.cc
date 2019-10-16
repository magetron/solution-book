#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
	inline double diff(double a, double b) {
		return abs(a - b);
	}

    int closestValue(TreeNode* root, double target) {
        if (!root) return -1;
		queue<TreeNode *> q;
		q.push(root);
		int ans = root -> val;
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* cur = q.front();
                q.pop();
				if (diff(cur -> val, target) < diff(ans, target)) ans = cur -> val;
				if (cur -> left) q.push(cur -> left);
				if (cur -> right) q.push(cur -> right);
			}
		}
		return ans;
    }
};

