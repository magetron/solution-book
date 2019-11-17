#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

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
		priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
		for (int i = 0; i < primes.size(); i++)
			pq.push({primes[i], primes[i], 0});
		vector<int> nums(n);
		nums[0] = 1;
		int i = 1;
		while (i < n) {
			auto tup = pq.top(); pq.pop();
			int n = get<0>(tup), p = get<1>(tup), index = get<2>(tup);
			//cout << n << " " << p << " " << index << " " << i << endl;
			if (n != nums[i - 1]) {
				nums[i] = n;
				i++;
			}
			pq.push({p * (ll)nums[index + 1], p, index + 1});
		}
		return nums[n - 1];
    }
};

int main () {
	vector<int> ps{2,7,13,19};
	Solution s;
	cout << s.nthSuperUglyNumber(12, ps) << endl;
	return 0;
}
