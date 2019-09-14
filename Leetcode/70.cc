#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int a = 1;
		int b = 2;
		for (int i = 3; i <= n; i++) {
			int tmp = a + b;
			a = b;
			b = tmp;
		}
		return b;
    }
};
	
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.climbStairs(5) << endl;
	return 0;
}
