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
		if (!citations.size()) return 0;
		int l = 0;
		int r = citations.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int tmp = citations.size() - mid;
			if (citations[mid] == tmp) return tmp;
			else if (citations[mid] < tmp) l = mid + 1;
			else r = mid - 1;
		}
		return citations.size() - l;
    }
};

int main () {
	Solution s;
	vector<int> c{1};
	cout << s.hIndex(c) << endl;
	return 0;
}
