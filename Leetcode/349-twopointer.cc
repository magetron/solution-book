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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		vector<int> ans;
		while (i < nums1.size() && j < nums2.size()) {
			int n1 = nums1[i], n2 = nums2[j];
			if (n1 == n2) {
				if (ans.size() == 0 || ans.back() != n1) ans.push_back(n1);
                i++; j++;
			} else if (n1 < n2) i++;
			else j++;
		}
		return ans;
	}
};


