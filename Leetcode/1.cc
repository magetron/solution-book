#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> dict;
		vector<int> ans(2, -1);
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) { 
			int comp = target - *it;
			map<int, int>::iterator dit = dict.find(comp);
			if (dit != dict.end()) {
				ans[0] = dit -> second;
				ans[1] = it - nums.begin();
				return ans;
			}
            dict.insert(pair<int, int>(*it, it - nums.begin()));
		}
        return ans;
    }
};

