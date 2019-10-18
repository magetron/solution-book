#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		int l = 0, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2;
			//cout << mid << endl;
            if (isBadVersion(mid)) r = mid;
			else l = mid + 1;
		}
		return l;
    }
};

