#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int reverse(int x) {
			vector<int> stack;
			bool negative = x < 0 ? true : false;
			long long n = abs((long long)x);
			while (n > 0) {
				stack.push_back(n % 10);
				n /= 10;
			}
			//for (auto it = stack.begin(); it != stack.end(); it++) cout << *it << " ";
			//cout << endl;
			int ans = 0;
			for (auto it = stack.begin(); it != stack.end(); it++) {
				long long buffer = (long long)ans * 10 + *it;
				if (buffer < INT_MAX) ans = buffer; else return 0;
			}
			return ans * (negative ? -1 : 1);
		}
};

int main () {
	Solution s;
	cout << s.reverse(-2147483648) << endl;
	return 0;
}

