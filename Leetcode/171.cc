#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
   		long k = 1;
		int ans = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++) {
			ans += k * (*it - 64);
			k = k * 26;
		}
		return ans;
    }
};


