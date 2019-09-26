#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string ans;
		while (n) {
			n--;
			ans.push_back(n % 26 + 65);
			n /= 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


