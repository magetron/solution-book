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
	bool cmp (vector<int>& a, vector<int>& b) {
		if (a.size() == b.size()) {
			int i = 0; 
			while (i < a.size()) {
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
				else i++;
			}
			return true;
		} else return a.size() > b.size();
	}

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
					
    }
};

int main () {
	vector<int> n1{3, 4, 6, 5};
	vector<int> n2{9, 1, 2, 5, 8, 3};
	Solution s;
	auto ans = s.maxNumber(n1, n2, 5);
	for (auto a : ans) cout << a << " "; cout << endl;
	return 0;
}
