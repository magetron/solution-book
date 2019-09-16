#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> res(k, 0);
		int i = 0;
		while (i >= 0) {
			res[i]++;
			if (res[i] > n) i--;
			else if (i == k - 1) ans.push_back(res);
			else {
				i++;
				res[i] = res[i - 1];
			}
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	auto ans = s.combine(5,3);
	for (auto as : ans) {
		for (auto i : as) cout << i << " ";
		cout << endl;
	}
	return 0;
}
