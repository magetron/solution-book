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

	inline bool max (int a, int b) {
		return a > b;
	}

	inline bool cmp (vector<int>& a, vector<int>& b) {
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


	inline void max_num(vector<int>& ans, vector<int>& ns, int k) {
		ans.clear();
		for (int i = 0; i < ns.size(); i++) {
			while (ns.size() - i + ans.size() > k && ans.size() > 0 && ns[i] > ans.back()) ans.pop_back();
			if (ans.size() < k) ans.emplace_back(ns[i]);
		}
	}


	inline void merge(vector<int>& ans, vector<int>& ns1, vector<int>& ns2, int k) {
		ans.clear();
		int i = 0, j = 0;
		bool checked = false, result = false;
		int it = 0;
		while (it < k && i < ns1.size() && j < ns2.size()) {
			if (ns1[i] > ns2[j]) {
				checked = false;
				ans.emplace_back(ns1[i]);
				i++; it++;
			} else if (ns1[i] < ns2[j]) {
				checked = false;
				ans.emplace_back(ns2[j]);
				j++; it++;
			} else {
				if (checked) {
					if (result) {
						ans.emplace_back(ns1[i]);
						i++; it++;
					} else {
						ans.emplace_back(ns2[j]);
						j++; it++;
					}
				} else {
					checked = true;
					int li = i + 1, lj = j + 1;
					while (li < ns1.size() && lj < ns2.size() && ns1[li] == ns2[lj]) { li++; lj++; }
					result = lj == ns2.size() || (li < ns1.size() && ns1[li] > ns2[lj]);
				}
			}
		}
		while (i < ns1.size()) {
			ans.emplace_back(ns1[i]); i++;
		}
		while (j < ns2.size()) {
			ans.emplace_back(ns2[j]); j++;
		}
	}

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans; ans.reserve(k);
		vector<int> sol; sol.reserve(k);
		vector<int> t1; t1.reserve(max(nums1.size(), k - nums2.size()));
		vector<int> t2; t2.reserve(max(nums2.size(), k - nums1.size()));
		for (int i = max(0, k - nums2.size()); i <= k && i <= nums1.size(); i++) {
			max_num(t1, nums1, i);
			max_num(t2, nums2, k - i);
			//for (int j = 0; j < i; j++) cout << t1[j]; cout << endl;
			//for (int j = 0; j < k - i; j++) cout << t2[j]; cout << endl;
			merge(sol, t1, t2, k);
			if (cmp(sol, ans)) ans = sol;
		}
		return ans;
    }
};