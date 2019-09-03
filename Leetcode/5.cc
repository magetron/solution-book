#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1) return s;
	string ans = "";
	int len = s.length();
	int gap = (numRows - 1) << 1;
	for (int i = 0; i < numRows; i++) {
		if (i == 0) {
			for (int j = 0; j < len; j++) if (j % gap == 0) ans += s.at(j);
			continue;
		}
		if (i == numRows - 1) {
			for (int j = gap >> 1; j < len; j++) if (j % gap == gap >> 1) ans += s.at(j);
			continue;
		}
		int agap = gap - i * 2;
		int bgap = gap - agap;
		int j = i;
		int count = 0;
		while (j < len) {
			ans += s.at(j);
			if (count % 2 == 0) j += agap; else j += bgap;
			count++;
		}
	}
	return ans;
}

int main () {
	string s("PAYPALISHIRING");
	cout << convert(s, 4) << endl;
	return 0;
}

