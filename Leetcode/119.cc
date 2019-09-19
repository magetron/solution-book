#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			vector<int> line(1, 1);
			int m = rowIndex;
			int d = 1;
			ll n = 1;
			for (int i = 0; i < (rowIndex + 1) / 2; i++) {
				n = n * m / d;
				d++;
				m--;
				line.push_back((int)n);
			}
			for (int i = (rowIndex + 1) / 2; i < rowIndex; i++) line.push_back(line[rowIndex - 1 - i]);
			return line;
		}
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Solution s;
	auto ans = s.getRow(3);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
