#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		if (numbers.size() < 2) return vector<int>();
		int i = 0;
		int j = numbers.size() - 1;
		while (i < j) {
			if (numbers[i] + numbers[j] == target) return vector<int>{i + 1, j + 1};
			else if (numbers[i] + numbers[j] > target) j--;
			else i++;
		}
		return vector<int>();
    }
};


