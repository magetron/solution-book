#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int s = 0;
		while (m != n) {
			s++;
			m >>= 1;
			n >>= 1;
		}
		return n <<= s;
    }
};
