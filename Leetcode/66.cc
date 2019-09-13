#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
  		digits[digits.size() - 1]++;
		int i = digits.size() - 1;
		while (i > 0 && digits[i] >= 10) {
			digits[i] -= 10;
			digits[--i]++;
		}
		if (digits[0] >= 10) {
			digits[0] -= 10;
			digits.insert(digits.begin(), 1);
		}
        return digits;
    }
};

