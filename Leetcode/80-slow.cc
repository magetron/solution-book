#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int i = 0;
		int r = nums.size();
		while (i < r) {
			int j = i + 1;
			while (j < r && nums[j] == nums[i]) j++;
			if (j > i + 2) for (int k = i + 2; k < j; k++) swap(nums[k], nums[--r]);
			sort(nums.begin() + ((j == i + 1) ? i + 1 : i + 2), nums.begin() + r);	
			if (j == i + 1) i++; else i += 2;
		}
		for (auto i : nums) cout << i << " ";
		cout << endl;
		return r;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> nums{0,0,1,1,1,1,2,3,3};
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}
