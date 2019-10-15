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
    int addDigits(int num) {
		return (num == 0 ? 0 : (num % 9 == 0 ? 9 : num % 9));
    }
};

