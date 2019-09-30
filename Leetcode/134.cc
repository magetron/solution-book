#include <bits/stdc++.h>
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int sum_g = 0;
		for (auto g : gas) sum_g += g;
		int sum_c = 0;
		for (auto c : cost) sum_c += c;
		if (sum_c > sum_g) return -1;
		int cur = 0;
		int debt = 0;
		int ans = 0;
		for (int i = 0; i < cost.size(); i++) {
			cur += gas[i] - cost[i];
			if (cur < 0) {
				debt -= cur;
				cur = 0;
				ans = i + 1;
			}
		}
		return (debt > cur ? -1 : ans);
    }
};

int main () {
	Solution s;
	vector<int> gas{5,5,1,3,4};
	vector<int> cost{8,1,7,1,1};
	cout << s.canCompleteCircuit(gas, cost) << endl;
	return 0;
}

