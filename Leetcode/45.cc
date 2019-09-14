#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		int prev = 0;
        int cur = 0;
		int new_cur = 0;
		int steps = 0;
		while (cur < nums.size() - 1) {
			steps++;
			for (int i = prev; i <= cur; i++) new_cur = max(new_cur, i + nums[i]);
			if (cur == new_cur) return -1;
			prev = cur;
			cur = new_cur;
		}
		return steps;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> nums{2,3,1,1,4};
	cout << s.jump(nums) << endl;
	return 0;
}
