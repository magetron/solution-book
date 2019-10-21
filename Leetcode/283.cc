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
    void moveZeroes(vector<int>& nums) {
		int i = 0;
		int j = 0;
    	while (i < nums.size()) {
			while (i < nums.size() && nums[i] == 0) i++;
			if (i < nums.size()) {
				swap(nums[i], nums[j]);
				i++; j++;
			}
		}
	}
};

int main () {
	Solution s;
	vector<int> n{1,2,3,3,0};
	s.moveZeroes(n);
	for (auto i : n) cout << i << " ";
	cout << endl;
	return 0;
}
