#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
	public:
		bool sstart (string& num, int pos, string& s) {
			int i = pos, j = 0;
			while (i < num.length() && j < s.length()) if (num[i] != s[j]) return false;
			else {
				i++; j++;
			}
			return j == s.length();
		}

		bool isAdditiveNumber (string num) {
			for (int i = 0; i < num.length() / 2; i++) {
				for (int j = i + 1; j < num.length() / 3 * 2; j++) {
					int p1 = i;
					int p2 = j;
					string s1 = num.substr(0, p1 + 1);
					if (s1.length() > 1 && s1[0] == '0') continue;
					string s2 = num.substr(p1 + 1, p2 - p1);
					if (s2.length() > 1 && s2[0] == '0') continue;
					do {
						//cout << p1 << " " << p2 << " " << s1 << " " << s2 << endl;
						ll n1 = stol(s1);
						ll n2 = stol(s2);
						string ns = to_string(n1 + n2);
						cout << ns << endl;
						if (!sstart(num, p2 + 1, ns)) break;
						s1 = s2; s2 = ns;
						p1 = p2; p2 += ns.length();
					} while (p2 < num.length() - 1);
					if (p2 == num.length() - 1) return true;
				}
			}
			return false;
		}
};







