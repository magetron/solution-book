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
    int hIndex(vector<int>& citations) {
		if (citations.size() == 0) return 0;
		if (citations.size() == 1) return min(1, citations.back());
		reverse(citations.begin(), citations.end());
		int l = 0, r = citations.size();
		while (l < r) {
            //cout << l << " " << r << endl;
			int mid = l + (r - l) / 2;
			if (citations[mid] >= mid + 1) l = mid + 1;
			else r = mid;
		}
		return max(l - 1, r);
    }
};

