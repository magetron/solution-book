#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int cur = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while (i >= 0 && j >= 0 && cur >= 0) {
			if (nums1[i] > nums2[j]) nums1[cur--] = nums1[i--];
			else nums1[cur--] = nums2[j--];
		}
		while (j >= 0 && cur >= 0) nums1[cur--] = nums2[j--];
		//for (auto i : nums1) cout << i << " ";
		//cout << endl;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> nums1 {4,5,6,0,0,0};
	vector<int> nums2 {1,2,3};
	Solution s;
	s.merge(nums1, 3, nums2, 3);
	return 0;
}
