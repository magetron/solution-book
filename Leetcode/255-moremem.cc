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
		stack<int> st;
		int low = INT_MIN;
		for (int i = 0; i < preorder.size(); i++)
			if (preorder[i] < low) return false;
			else {
				while (!st.empty() && preorder[i] > st.top()) {
					low = st.top(); st.pop();
				}
				st.push(preorder[i]);
			}
		return true;
    }
};

