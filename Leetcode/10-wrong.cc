#include <bits/stdc++.h>

using namespace std;

// O(n) solution will not be able to tackle a*b*c* matching problems, since after a* whether its going to be b / c is unknown, thus ambiguities

class Solution {
	public:

		void print (string s, string p, int i, int j) {
			cout << s.substr(0, i) << " " << p.substr(0, j) << endl;
		}

		void preprocess (string& s) {
			int lenS = s.length();
			int i = 0;
			while (i < lenS - 1) {
				cout << i << endl;
				bool rep = false;
				if (i + 1 < lenS && s.at(i + 1) == '*') rep = true;
				char nextChar;
				if (i + 2 < lenS && rep) nextChar = s.at(i + 2); else nextChar = s.at(i + 1);
				int repCount = 0;
				if (s.at(i) == nextChar) {
					int j = i;
					while (j < lenS && s.at(j) == nextChar) {
						j++;
						if (j < lenS && s.at(j) == '*') {
							repCount++;
							j++;
						}
					}
					int actualChar = (j - i + 1) - repCount * 2;
					string newPattern("");
					for (int k = 0; k < actualChar - 1; k++) newPattern += nextChar;
					if (repCount > 0) newPattern += (string(1, nextChar) + "*");
					s = s.substr(0, i) + newPattern + s.substr(j, lenS);
					lenS = s.length();
					i = j;
				} else i++;
			}
		}
					

		bool isMatch(string s, string p) {
			int i = 0;
			int j = 0;
			int lenS = s.length();
			preprocess(p);
			int lenP = p.length();
			cout << p << endl;
			while (i < lenS && j < lenP) {
				print(s, p, i ,j);
				bool rep = false;
				if (j + 1 < lenP && p.at(j + 1) == '*') rep = true;
				if (!rep) {
					if (s.at(i) == p.at(j)) { i++; j++; } else if (p.at(j) == '.') { i++; j++; } else return false;
				} else {
					char repChar = p.at(j);
					if (repChar != '.') {
						j += 2;	
						while (i < lenS && s.at(i) == repChar) i++;
					} else {
						j += 2;
						if (j < lenP) {
							char nextChar = p.at(j);
							while (i < lenS && s.at(i) != nextChar) i++;
							if (i == lenS) return false;
						} else return true;
					}
				}
			}
			if (i == lenS && j == lenP) return true;
			return false;
		}
};

int main () {
	Solution sol;
	string s("a");
	string p("a*");
	cout << sol.isMatch(s, p) << endl;
	return 0;
}
