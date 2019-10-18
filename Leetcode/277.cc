#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
		int c = 0;
		int cur = 0;
		while (c < n) {
			bool found = false;
			for (int i = cur + 1; i < n; i++) if (i != cur && knows(cur, i)) {
				cur = i;
				found = true;
				break;
			}
			if (!found) {
                for (int i = 0; i < n; i++) if (i != cur && knows(cur, i)) return -1;
				for (int i = 0; i < n; i++) if (i != cur && !knows(i, cur)) return -1;
				return cur;
			}
			c++;
		}
		return -1;
    }
};

