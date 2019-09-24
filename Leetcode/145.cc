#include<bits/stdc++.h>
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

    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
		vector<int> ans;
		stack<TreeNode *> st;
		st.push(root);
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			st.pop();
			if (!st.empty() && st.top() == cur) {
				if (cur -> right) {
					st.push(cur -> right);
					st.push(cur -> right);
				}
				if (cur -> left) {
					st.push(cur -> left);
					st.push(cur -> left);
				}
			} else ans.push_back(cur -> val);
		}
		return ans;
    }
};

