#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	void print (vector<int>& a) {
		for (auto i : a) cout << i << " ";
		cout << endl;
	}

    int jump(vector<int>& nums) {
		vector<int> dp(nums.size(), INT_MAX);
		int cur = 0;
		int prev = 0;
		int steps = 0;
		while (cur < nums.size() - 1) {
			int new_cur = 0;
			for (int i = prev; i <= cur; i++) if (nums[i] + i > new_cur) new_cur = nums[i] + i;
			prev = cur;
			cur = new_cur;
			steps++;
			if (prev == cur) return -1;
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
