#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= k + 1) {
			unordered_set<int> s(nums.begin(), nums.end());
			return s.size() != nums.size();
		}
		unordered_set<int> s(nums.begin(), nums.begin() + k + 1);
		if (s.size() != k + 1) return true;
		for (int i = k + 1; i < nums.size(); i++) {
			s.erase(nums[i - k - 1]);
			s.insert(nums[i]);
			cout << s.size() << endl;
			if (s.size() != k + 1) return true;
		}
		return false;	
	}
};

int main () {
	Solution s;
	vector<int> n{1,0,1,1};
	cout << s.containsNearbyDuplicate(n, 0) << endl;
	return 0;
}
