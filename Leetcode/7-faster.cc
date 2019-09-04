#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int reverse(int x) {
        	long ans = 0;
			long y = x;
			while (y != 0) {
				ans = ans * 10 + y % 10;
				y /= 10;
			}
			if (ans > INT_MAX || ans < INT_MIN) return 0;
			else return ans;
        }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution s;
	cout << s.reverse(-2147483648) << endl;

	return 0;
}
