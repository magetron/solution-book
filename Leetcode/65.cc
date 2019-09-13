#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isWholeNumber (string& s, int l, int r) {
		if (l > r) return false;
		for (int i = l; i <= r; i++) if (s[i] < '0' || s[i] > '9') return false;
		return true;
	}

	bool isInteger (string& s, int l, int r) {
		if (l > r) return false;
		if (s[l] == '+' || s[l] == '-') return isWholeNumber(s, l + 1, r);
		else return isWholeNumber(s, l, r);
	}

	bool isDecimal (string& s, int l, int r) {
		int d_pos = -1;
		for (int i = l; i <= r; i++) if (s[i] == '.') { d_pos = i; break; }
		if (d_pos == -1) return false;
		else {
			if (d_pos == l) return isWholeNumber(s, d_pos + 1, r);
			else if (d_pos == r) return isInteger(s, l, d_pos - 1);
			else return (isInteger(s, l, d_pos - 1) || (d_pos - 1 == l && (s[l] == '+' || s[l] == '-') )) && isWholeNumber(s, d_pos + 1, r);
		}
	}

	bool isExponent (string& s, int l, int r) {
		int e_pos = -1;
		for (int i = l; i <= r; i++) if (s[i] == 'e') { e_pos = i; break; }
		if (e_pos == -1) return false;
		else return (isDecimal(s, l, e_pos - 1) || isInteger(s, l, e_pos - 1)) && isInteger(s, e_pos + 1, r);
	}

	void trim (string& s) {
		int i = 0;
		while (s[i] == ' ') i++;
		s = s.substr(i, s.length() - i);
		i = s.length() - 1;
		while (s[i] == ' ') i--;
		s = s.substr(0, i + 1);
	}

    bool isNumber(string s) {
		trim(s);
    	return isExponent(s, 0, s.length() - 1) || isDecimal(s, 0, s.length() - 1) || isInteger(s, 0, s.length() - 1);     
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << (s.isNumber(" +.3  ") ? "true" : "false") << endl;
	return 0;
}

