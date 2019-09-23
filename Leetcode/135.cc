#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int up = 0, down = 0, ans = 1, peak = 0;
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				ans += 1 + (++up);
				down = 0;
				peak = up;
			} else if (ratings[i] == ratings[i - 1]) {
				up = 0;
				down = 0;
                peak = 0;
				ans++;
			} else {
				up = 0;
				ans += 1 + ++down + (down > peak ? 0 : -1);
			}
            //cout << ans << endl;
        }
		return ans;
	}
};



