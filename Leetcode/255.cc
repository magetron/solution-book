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
	bool verifyPreorder(vector<int>& preorder) {
		int low = INT_MIN;
		int sttop = -1;
		for (int i = 0; i < preorder.size(); i++) {
			if (preorder[i] < low) return false;
			else {
				while (sttop != -1 && preorder[sttop] < preorder[i]) {
					low = preorder[sttop--];
				}
				preorder[++sttop] = preorder[i];
			}
		}
		return true;
    }
};

