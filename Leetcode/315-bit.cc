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

	inline void update (int pos, vector<int>& bit) {
		while (pos < bit.size()) {
			bit[pos]++;
			pos += (pos & (-pos));
		}
	}

	inline int get (int pos, vector<int>& bit) {
		int s = 0;
		while (pos > 0) {
			s += bit[pos];
			pos -= (pos & (-pos));
		}
		return s;
	}

    vector<int> countSmaller(vector<int>& nums) {
		if (!nums.size()) return {};
		int minima = INT_MAX, maxima = INT_MIN;
		for (int n : nums) minima = min(minima, n);
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = nums[i] - minima + 1;
			maxima = max(nums[i], maxima);
		}
		vector<int> bit(maxima + 1, 0);
		vector<int> ans;
		for (int i = nums.size() - 1; i >= 0; i--) {
			ans.push_back(get(nums[i] - 1, bit));
			update(nums[i], bit);
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};


int main () {
	Solution s;
	vector<int> n{5,2,6,1};
	auto ans = s.countSmaller(n);
	for (auto a : ans) cout << a << " "; cout << endl;
	return 0;
}
