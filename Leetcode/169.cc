#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int ans;
		int count = 0;
		for (auto n : nums) {
			if (count == 0) ans = n;
			if (n != ans) count--; else count++;
		}
		return ans;
    }
};
