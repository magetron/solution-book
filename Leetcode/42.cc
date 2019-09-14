#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
		int l_max = -1;
		int r = height.size() - 1;
		int r_max = -1;
		int ans = 0;
		while (l < r) {
			if (height[l] > height[r]) {
				if (height[r] > r_max) r_max = height[r]; else ans += r_max - height[r];
				r--;
			} else {
				if (height[l] > l_max) l_max = height[l]; else ans += l_max - height[l];
				l++;
			}
		}
		return ans;
    }
};



