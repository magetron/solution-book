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
    int candy(vector<int>& ratings) {
		vector<int> c(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++)
			if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
        for (auto i : c) cout << i << " ";
        cout << endl;
		for (int i = ratings.size() - 2; i >= 0; i--)
			if (ratings[i] > ratings[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        for (auto i : c) cout << i << " ";
        cout << endl;
		int ans = 0;
		for (auto i : c) ans += i;
		return ans;
	}
};
