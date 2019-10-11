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
    bool isStrobogrammatic(string num) {
		string cpy = num;
		for (auto& ch : cpy) {
			if (ch == '6') ch = '9';
			else if (ch == '9') ch = '6';
			else if (ch == '1' || ch == '8' || ch == '0' ) continue;
			else return false;
		}
		//cout << cpy << endl;
		reverse(cpy.begin(), cpy.end());
		//cout << cpy << endl;
		return cpy == num;
    }
};

int main () {
	Solution s;
	cout << s.isStrobogrammatic("101") << endl;
	return 0;
}
