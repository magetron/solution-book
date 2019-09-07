#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		for (auto it = nums.begin(); it != nums.end(); it++) {
			int cur = *it;
			auto fit = next(it, 1);
			while (fit != nums.end() && *fit == cur) {
				nums.erase(fit--);
				fit++;
			}
		}
		return nums.size();
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution s;
	s.removeDuplicates(nums);
	for (auto it = nums.begin(); it != nums.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
