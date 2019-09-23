#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		unordered_set<int> s;
		long sum = 0;
		for (auto i : nums) {
			s.insert(i);
			sum += i;
		}
		long ssum = 0;
		for (auto i : s) ssum += i;
		return (ssum * 3 - sum) / 2;
    }
};
