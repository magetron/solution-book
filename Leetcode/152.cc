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
    int maxProduct(vector<int>& nums) {
		int lmax = 1;
		int lmin = 1;
		int olmax, olmin;
		int ans = INT_MIN;
		for (auto& i : nums) {
			olmax = lmax;
			olmin = lmin;
			lmax = max(max(i * olmax, i), olmin * i);
			lmin = min(min(i * olmin, i), olmax * i);
			ans = max(max(ans, lmax), olmin * i);
		}
		return ans;	
    }
};

int main () {
	Solution s;
	vector<int> n{-2,3,-4,-5,-3};
	cout << s.maxProduct(n) << endl;
	return 0;
}
