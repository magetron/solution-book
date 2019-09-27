#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
    	long k = 5;
		int ans = 0;
		while (k <= n) {
			ans += n / k;
			k *= 5;
    	}
		return ans;
	}
};
