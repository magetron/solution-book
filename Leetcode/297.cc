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
class Codec {
public:

	void preorder(TreeNode* root, string& ans) {
		if (!root) {
			ans.push_back('@'); ans.push_back('|');
			return;
		}
		ans += to_string(root -> val);
		ans.push_back('|');
		preorder(root -> left, ans);
		preorder(root -> right, ans);
		return;
	}

    string serialize(TreeNode* root) {
		string ans;
		preorder(root, ans);
		return ans;
    }

	TreeNode* construct(string& data, int& pos) {
		int i = pos + 1;
		while (data[i] != '|') i++;
		string str = data.substr(pos, i - pos);
		pos = i + 1;
		if (str == "@") {
			return nullptr;
		} else {
			TreeNode* root = new TreeNode(stoi(str));
			root -> left = construct(data, pos);
			root -> right = construct(data, pos);
			return root;
		}
	}

    TreeNode* deserialize(string data) {
		int pos = 0;
		return construct(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

