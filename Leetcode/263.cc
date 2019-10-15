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
    bool isUgly(int num) {
        if (num <= 0) return false;
		while (!(num & 1)) num >>= 1;
		while (!(num % 3)) num /= 3;
		while (!(num % 5)) num /= 5;
		return num == 1;
    }
};

