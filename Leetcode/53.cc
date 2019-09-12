#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int maxSubArray (vector<int>& a) {
			int suff_m = a[0];
			int m = a[0];
			for (int i = 1; i < a.size(); i++) {
				if (a[i] > suff_m + a[i]) suff_m = a[i]; else suff_m += a[i];
				if (suff_m > m) m = suff_m;
				cout << suff_m << " " << m << endl;
			}
			return m;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums{-2,-1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}
