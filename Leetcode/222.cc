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
	int rdfs(TreeNode* root) {
		if (!root) return 0;
		else return 1 + rdfs(root -> right);
	}

	bool exist (int mid, int d, TreeNode* root) {
		while (d) {
			d--;
			int k = 1 << d;
			if (mid / k) root = root -> right;
			else root = root -> left;
			mid %= k;
		}
		return (root != nullptr);
	}

    int countNodes(TreeNode* root) {
    	int d = rdfs(root);    
    	int l = 0;
		int r = 1 << d;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (exist(mid, d, root)) l = mid + 1;
			else r = mid;
		}
		return (1 << d) - 1 + l;
	}
};

