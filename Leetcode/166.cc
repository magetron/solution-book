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
    string fractionToDecimal(int nn, int dd) {
		bool neg = false;
		long n = (long)nn;
		long d = (long)dd;
		//cout << n << " " << d << endl;
		if ((n > 0 && d < 0) || (n < 0 && d > 0)) neg = true;
		n = abs(n);
		d = abs(d);
		string ans = to_string(n / d);
		if (n % d == 0) return (neg ? "-" + ans : ans);
		ans.push_back('.');
		string s = "";
		unordered_map<long, long> dict;
		bool loop = false;
		int loop_pos = -1;
		n %= d;
		int pos = 0;
		while (n % d) {
			n *= 10;
			auto found = dict.find(n);
			if (found != dict.end()) {
				loop_pos = (*found).second;
				loop = true;
				break;
			}
			dict.insert(make_pair(n, pos));
			s += to_string(n / d);
			pos++;
			n %= d;
		}
		if (!loop) ans += s;
		else {
			s.insert(loop_pos, "(");
			ans += s + ")";
		}
		return (neg ? "-" + ans : ans);
    }
};

int main () {
	Solution s;
	cout << s.fractionToDecimal(-2147483648, 1) << endl;
	return 0;
}
