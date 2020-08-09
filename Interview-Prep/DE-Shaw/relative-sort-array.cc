#pragma optimize ("Ofast")

#include <bits/stdc++.h>

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
   	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int, int> dict;
		for (size_t i = 0; i < arr2.size(); i++) {
			dict.insert({arr2[i], i});
		}
		sort(arr1.begin(), arr1.end(), [](const int& a, const int& b) -> bool {
			if (dict.find(a) != dict.end() && dict.find(b) != dict.end()) {
				return dict[a] < dict[b];
			} else if (dict.find(a) != dict.end()) {
				return true;
			} else if (dict.find(b) != dict.end()) {
				return false;
			} else {
				return a < b;
			}
		});
    } 
};
