#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void print (vector<int>& a) {
		for (auto i : a) cout << i << " ";
		cout << endl;
	}

    int firstMissingPositive(vector<int>& nums) {
       for (auto& i : nums) if (i > nums.size() || i <= 0) i = 0;
	   //print(nums);
	   for (auto i : nums) if (i % (nums.size() + 1) > 0) nums[i % (nums.size() + 1) - 1] += nums.size() + 1;
	   //print(nums);
	   for (auto it = nums.begin(); it != nums.end(); it++) if (*it < nums.size() + 1) return it - nums.begin() + 1;
	   return nums.size() + 1;
	}
};


int main () {
	Solution s;
	vector<int> nums{3,4,-1,1};
	cout << s.firstMissingPositive(nums) << endl;
	return 0;
}
	
