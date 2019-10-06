#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    
    inline int sqr (int n) {
        return n * n;
    }
    
	int countPrimes(int n) {
    	bitset<1 << 21> bs;
		for (int i = 2; sqr(i) < n; i++) 
			if (!bs[i])
				for (int j = sqr(i); j < n; j += i) bs[j] = 1;
		return max(n - (int)bs.count() - 2, 0);
	}
};


