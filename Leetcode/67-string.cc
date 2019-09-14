#include <bits/stdc++.h>
#define si short int

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		if (a.length() < b.length()) swap(a, b);
        int i = a.size() - 1;
		int j = b.size() - 1;
		si carry = 0;
		si sum = 0;
		string ans;
		while (i >= 0 && j >= 0) {
			sum = (a[i] - 48) + (b[j] - 48) + carry;
			carry = sum / 2;
			sum %= 2;
			ans.push_back(sum + 48);
			i--; j--;
		}
		while (i >= 0) {
			sum = (a[i] - 48) + carry;
			carry = sum / 2;
			sum %= 2;
			ans.push_back(sum + 48);
			i--;
		}
		if (carry) ans.push_back(1 + 48);
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.addBinary("1010", "1011") << endl;
	return 0;
}

