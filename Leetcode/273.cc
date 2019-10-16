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

	inline string digitToStr (int d, bool actZero) {
		switch (d) {
			case 1:
				return "One";
				break;
			case 2:
				return "Two";
				break;
			case 3:
				return "Three";
				break;
			case 4:
				return "Four";
				break;
			case 5:
				return "Five";
				break;
			case 6:
				return "Six";
				break;
			case 7:
				return "Seven";
				break;
			case 8:
				return "Eight";
				break;
			case 9:
				return "Nine";
				break;
		}
		if (d == 0 && actZero) return "Zero"; else return "";
	}

	inline string i100ToStr (int d) {
		int a = d / 10;
		int b = d % 10;
		if (a == 0) return digitToStr(b, false);
		else if (a == 1) {
			switch (b) {
				case 0:
					return "Ten";
					break;
				case 1:
					return "Eleven";
					break;
				case 2:
					return "Twelve";
					break;
				case 3:
					return "Thirteen";
					break;
				case 4:
					return "Fourteen";
					break;
				case 5:
					return "Fifteen";
					break;
				case 6:
					return "Sixteen";
					break;
				case 7:
					return "Seventeen";
					break;
				case 8:
					return "Eighteen";
					break;
				case 9:
					return "Nineteen";
					break;
			}
		} else if (a == 2) {
			return "Twenty " + digitToStr(b, false);
		} else if (a == 3) {
			return "Thirty " + digitToStr(b, false);
		} else if (a == 4) {
			return "Forty " + digitToStr(b, false);
		} else if (a == 5) {
			return "Fifty " + digitToStr(b, false);
		} else if (a == 6) {
			return "Sixty " + digitToStr(b, false);
		} else if (a == 7) {
			return "Seventy " + digitToStr(b, false);
		} else if (a == 8) {
			return "Eighty " + digitToStr(b, false);
		} else if (a == 9) {
			return "Ninety " + digitToStr(b, false);
		}
		return "";
	}

	inline string i1000ToStr (int n) {
		int a = n / 100;
		int b = n % 100;
		if (a > 0) return digitToStr(a, false) + " Hundred " + i100ToStr(b);
		else return i100ToStr(b);
	}

	inline string lvlToStr (int lvl) {
		switch (lvl) {
			case 1:
				return "Thousand";
				break;
			case 2:
				return "Million";
				break;
			case 3:
				return "Billion";
				break;
			case 4:
				return "Trillion";
				break;
			default:
				return "";
				break;
		}
	}

	inline string trim (string s) {
		string ans = "";
		int i = 0;
		while (i < s.length()) {
			if (s[i] >= 'A' && s[i] <= 'z') {
				int j = i + 1;
				while (j < s.length() && s[j] >= 'A' && s[j] <= 'z') j++;
				ans += s.substr(i, j - i) + " ";
				i = j + 1;
			} else i++;
		}
		ans.pop_back();
		return ans;
	}

    string numberToWords(int num) {
		if (num == 0) return "Zero";
		string ans = "";
		int lvl = -1;
		while (num) {
			int cur = num % 1000;
			num /= 1000;
			lvl++;
			if (cur == 0) continue;
			ans = i1000ToStr(cur) + " " + lvlToStr(lvl) + " " + ans;
		}
		return trim(ans);
    }
};

int main () {
	Solution s;
	cout << s.numberToWords(50868) << endl;
	return 0;
}
