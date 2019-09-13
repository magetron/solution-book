#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	const vector<int> fac{1,1,2,6,24,120,720,5040,40320,362880};

    string getPermutation(int n, int k) {
    	int org_n = n;
		vector<int> arr{1,2,3,4,5,6,7,8,9};
		string ans = "";
		k--;
		while (k > 0) {
			int pos = k / fac[--n];
			ans += arr[pos] + 48;
			arr.erase(arr.begin() + pos);
			k %= fac[n];
		}
		int org_len = ans.length();
		for (int i = 0; i < org_n - org_len; i++) ans += arr[i] + 48;	
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.getPermutation(4, 1) << endl;
	return 0;
}
