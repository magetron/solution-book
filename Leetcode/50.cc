#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
	public:
		double myPow(double x, int nn) {
			if (nn == 0) return 1;
			long n = long(nn);
			x = (n > 0) ? x : 1 / x;
			n = abs(n);
			double res = x;
			ll i = 1;
			int count = 0;
			vector<double> dict(32, 0);
			dict[0] = res;
			while (i < n) {
				i <<= 1;
				if (i > n) break;
				res *= res;
				dict[++count] = res;	
			}
			if (i > n) i >>= 1;
			n -= i;
			//cout << n << endl;
			while (n > 0) {
				int i = 1;
				int count = 0;
				while (i < n) {
					i <<= 1;
					count++;
				}
				if (i > n) { i >>= 1; count--; }
				n -= i;	
				res *= dict[count];
			}
			return res;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.myPow(2.1, 3) << endl;
	return 0;
}
