#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void helper (bitset<16>& bits, vector<int>& ans, int k) {
		if (k == 0) {
			//cout << bits.to_ulong() << endl;
			ans.push_back(bits.to_ulong());
			return;
		}
		helper(bits, ans, k - 1);
		bits.flip(k - 1);
		helper(bits, ans, k - 1);
	}

    vector<int> grayCode(int n) {
		bitset<16> bits;
		vector<int> ans;
		helper(bits, ans, n);
		return ans;
    }				
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution s;
	auto ans = s.grayCode(2);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
	
