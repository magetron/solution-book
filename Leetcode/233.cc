#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
		int ans = 0;
		for (ll i = 10; i / 10 <= n; i *= 10)		
			ans += n / i * (i / 10) + min(max(n % i - i / 10 + 1, (ll)0), i / 10);

		//bit of analysis
		//max is a calc of 11, 12, 13 ... 19, such that if it is to 103, its gonna be smaller than 0, such that we do a max to get rid of cases like 103
		//min is a clac of 11..19, 20, 21, obviously total count will not exceed 10, or i / 10 given a larger i
		return ans;	
    }
};

