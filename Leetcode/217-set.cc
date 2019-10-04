#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		return s.size() == nums.size();
    }
};
