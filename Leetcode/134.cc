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
		int gass = 0, lack = 0;
		int ans = 0;
		for (int i = 0; i < gas.size(); i++) {
			gass += gas[i] - cost[i];
			if (gass < 0) {
				lack += - gass;
				gass = 0;
				ans = i + 1;
			}
		}
		if (lack > gass) return -1; else return ans;
    }
};

int main () {
	Solution s;
	vector<int> gas{5,5,1,3,4};
	vector<int> cost{8,1,7,1,1};
	cout << s.canCompleteCircuit(gas, cost) << endl;
	return 0;
}

