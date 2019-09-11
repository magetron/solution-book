#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
  		int cur = 0;
		int prev = 0;
		while (cur < nums.size() - 1) {
			int new_cur = 0;
			for (int i = prev; i <= cur; i++) new_cur = max(new_cur, i + nums[i]);
			if (cur == new_cur) return false;
			prev = cur;
			cur = new_cur;
		}
		return true;
    }
};
