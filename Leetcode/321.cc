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
		vector<int> n1(nums1);
		vector<int> n2(nums2);
		sort(n1.begin(), n1.end(), greater<int>());
		sort(n2.begin(), n2.end(), greater<int>());
		// optimise to sort top k elements;
		for (int i = 0; i <= k && i <= nums1.size() && k - i <= nums2.size(); i++) {
			int j = k - i;
			int n1_bar = i > 0 ? n1[i - 1] : 10;
			int n2_bar = j > 0 ? n2[j - 1] : 10;
			cout << n1_bar << " " << n2_bar << endl;
			vector<int> p1; p1.reserve(i);
			vector<int> p2; p2.reserve(j);
			for (int n : nums1) if (n >= n1_bar) p1.push_back(n);
			for (int n : nums2) if (n >= n2_bar) p2.push_back(n);
			for (auto p : p1) cout << p << " "; cout << endl;
			for (auto p : p2) cout << p << " "; cout << endl;
			cout << endl;
		}
		return {};
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
