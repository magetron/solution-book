#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (auto i : nums) {
			if (s.find(i) != s.end()) return false;
			s.insert(i);
		}
		return true;
    }
};
