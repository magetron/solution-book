#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int l = -1;
			int r = nums.size();
			int i = 0;
			short int dir = +1;
			while (i < r && i > l) {
				//cout << i << " " << l << " " << r << endl;
				int cur_num = nums[i];
				switch (nums[i]) {
					case 0:
						swap(nums[++l], nums[i]);
						i = l + 1; dir = + 1;
						break;
					case 2:
						swap(nums[--r], nums[i]);
						i = r - 1; dir = - 1;
						break;
					case 1:
						if (dir == +1) i++; else i--;
				}
				//for (auto ii :nums) cout << ii << " ";
				//cout << endl;
			}
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{0,0,1,1,2,2};
	s.sortColors(nums);
	for (auto i : nums) cout << i << " ";
	cout << endl;
	return 0;
}
