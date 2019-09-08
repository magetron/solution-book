#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0) return -1;
		ll ans = 0;
		ll a = abs((ll)dividend);
		ll b = abs((ll)divisor);
        //cout << b << endl;
		while (a >= b) {
			ll tmp = b; ll res = 1;
			while (a >= tmp) {
				tmp <<= 1;
				res <<= 1;
			}
			a -= (tmp >> 1);
			ans += (res >> 1);
		}
		//cout << ans << endl;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ans = - ans;
		if (ans > INT_MAX) return INT_MAX; 
		else return ans;
    }
};

int main () {
	Solution s;
	cout << s.divide(1, 1);
	return 0;
}
