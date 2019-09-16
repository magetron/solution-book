#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
		for (int i = 0; i < nums.size(); i++) 
			if (l - 2 < 0 || nums[i] != nums[l - 2]) nums[l++] = nums[i];
		return l;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> nums{1,1,1,2,2,3};
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}

