#include <bits/stdc++.h>
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
	vector<string> helper(TreeNode* root) {
        if (root == nullptr) return vector<string>();
		if (!root -> left && !root -> right) return vector<string>{string(1, (char)(root -> val + 48))};
		vector<string> left, right;
		if (root -> left) left = helper(root -> left);
		if (root -> right) right = helper(root -> right);
		left.insert(left.end(), right.begin(), right.end());
		for (string& s : left) s = (char)(root -> val + 48) + s;
		return left;
	}

    int sumNumbers(TreeNode* root) {
		auto arr = helper(root);
		int ans = 0;
		for (string s : arr) ans += stoi(s);
		return ans;
    }
};
