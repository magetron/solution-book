#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int __ = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    void recoverTree(TreeNode* root) {
		TreeNode* cur = root, *prev = nullptr;
		TreeNode* first = nullptr, *second = nullptr ;
		while (cur) {
			if (!cur -> left) {
                //cout << cur -> val << " ";
				if (prev && prev -> val >= cur -> val) {
					if (!first) first = prev;
					if (first) second = cur;
				}
				prev = cur;
				cur = cur -> right;
			} else {
				TreeNode* l = cur -> left;
				while (l -> right && l -> right != cur) l = l -> right;
				if (!l -> right) {
					l -> right = cur;
					cur = cur -> left;
				} else {
					l -> right = nullptr;
                    //cout << cur -> val << " ";
					if (prev && prev -> val >= cur -> val) {
						if (!first) first = prev;
						if (first) second = cur;
					}
					prev = cur;
					cur = cur -> right;
				}
			}
		}
		swap(first -> val, second -> val);
    }
};

