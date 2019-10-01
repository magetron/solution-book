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
    uint32_t reverseBits(uint32_t n) {
		bitset<32> bs(n);
        for (int i = 0; i < 16; i++) {
            bool tmp = bs[i];
            bs[i] = bs[31 - i];
            bs[31 - i] = tmp;
        }
        return bs.to_ulong();
    }
};

