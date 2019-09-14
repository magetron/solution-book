#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		n++;
        double Phi = (1 + sqrt(5)) / 2;
		double phi = -1 / Phi;
		return (int)((pow(Phi, n) - pow(phi, n)) / sqrt(5));
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.climbStairs(1) << endl;
	return 0;
}
	
