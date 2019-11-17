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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> states(primes.size(), 0);
		vector<int> nums;
		nums.push_back(1);
		for (int i = 1; i < n; i++) {
			int n = INT_MAX;
			for (int j = 0; j < primes.size(); j++) n = min(n, nums[states[j]] * primes[j]);
			nums.push_back(n);
			for (int j = 0; j < primes.size(); j++) if (nums[states[j]] * primes[j] == n) states[j]++;
		}
		return nums[n - 1];
	}
};

int main () {
	Solution s;
	vector<int> ps{2,7,13,19};
	int ans = s.nthSuperUglyNumber(12, ps);
	cout << "ans = " << ans << endl;
	return 0;
}
