#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		long x_reverse = 0;
		int y = x;
		while (y > 0) {
			x_reverse = x_reverse * 10 + y % 10;
			y /= 10;
		}
		if (x_reverse <= INT_MAX && x_reverse == x) return true;
		return false;
    }
};

int main () {
	Solution s;
	cout << s.isPalindrome(1234554321) << endl;
	return 0;
}
