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
    void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
    }
};

int main () {
	Solution s;
	vector<int> n{1,2,3,4,5,6};
	s.rotate(n, 3);
	for (auto i : n) cout << i << " "; cout << endl;
	return 0;
}
