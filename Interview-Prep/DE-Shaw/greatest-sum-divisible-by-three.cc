#pragma optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
    	int sum = 0;
		for (int n : nums) sum += n;
		if (sum % 3 == 0) return sum;
		else if (sum % 3 == 1) {
			int minLeft1 = INT_MAX;
			int minLeft21 = INT_MAX;
			int minLeft22 = INT_MAX;
			for (int n : nums) {
				if (n % 3 == 1 && n < minLeft1) minLeft1 = n;
				else if (n % 3 == 2) {
					if (n <= minLeft21) {
						minLeft22 = minLeft21;
						minLeft21 = n;
					} else if (n < minLeft22) {
						minLeft22 = n;
					}
				}
			}
			if (minLeft1 == INT_MAX && (minLeft21 == INT_MAX || minLeft22 == INT_MAX)) return 0;
			else if (minLeft1 == INT_MAX) return sum - minLeft21 - minLeft22;
			else if (minLeft21 == INT_MAX || minLeft22 == INT_MAX) return sum - minLeft1;
			else return (sum - minLeft1 > sum - minLeft21 - minLeft22 ? sum - minLeft1 : sum - minLeft21 - minLeft22);
		} else {
			int minLeft2 = INT_MAX;
			int minLeft11 = INT_MAX;
			int minLeft12 = INT_MAX;
			for (int n : nums) {
				if (n % 3 == 2 && n < minLeft2) minLeft2 = n;
				else if (n % 3 == 1) {
					if (n <= minLeft11) {
						minLeft12 = minLeft11;
						minLeft11 = n;
					} else if (n < minLeft12) {
						minLeft12 = n;
					}
				}
			}
			if (minLeft2 == INT_MAX && (minLeft11 == INT_MAX || minLeft12 == INT_MAX)) return 0;
			else if (minLeft2 == INT_MAX) return sum - minLeft11 - minLeft12;
			else if (minLeft11 == INT_MAX || minLeft12 == INT_MAX) return sum - minLeft2;
			else return (sum - minLeft2 > sum - minLeft11 - minLeft12 ? sum - minLeft2 : sum - minLeft11 - minLeft12);
		}
    }
};
