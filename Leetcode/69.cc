#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	inline long sqr(int x) {
		return (long)x * x;
	}

    int mySqrt(int x) {
		if (x == 0) return 0;
		if (x < 4) return 1;
		if (x < 9) return 2;
		int l = 1;
		int r = x / 2;
		while (l <= r) {
			//cout << l << " " << r << endl;
			int mid = l + (r - l) / 2;
			//cout << mid << endl;
			if (sqr(mid) == x || (sqr(mid) < x && sqr(mid + 1) > x)) return mid;
			else if (sqr(mid) < x) l = mid + 1;
			else r = mid - 1;
		}
		return -1;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("69.ans", "w", stdout);
	Solution s;
	cout << s.mySqrt(144) << endl;
	//fclose(stdout);
	return 0;
}
