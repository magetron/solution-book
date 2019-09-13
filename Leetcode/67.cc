#include <bits/stdc++.h>
#define ll __uint128_t
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		ll sum = 0;
		ll p = 1;
    	for (auto it = a.rbegin(); it != a.rend(); it++) {
			if (*it == 49) sum += p;
			p <<= 1;
		}
		p = 1;
		for (auto it = b.rbegin(); it != b.rend(); it++) {
			if (*it == 49) sum += p;
			p <<= 1;
		}
        if (sum == 0) return "0";
		int m = max(a.length(), b.length());
		string ans;
        p = 1;
		while (p < sum) p <<= 1;
		if (p > sum) p >>= 1;
		while (p > 0) {
			if (sum >= p) {
				ans += "1"; 
				sum -= p;
			} else ans += "0";
			p >>= 1;
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.addBinary("0", "0") << endl;
	return 0;
}

