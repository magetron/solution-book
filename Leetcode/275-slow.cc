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
		reverse(citations.begin(), citations.end());
		for (int i = 0; i < citations.size(); i++) {
			if (citations[i] < i + 1) return i;
		}
		return citations.size();
    }
};

