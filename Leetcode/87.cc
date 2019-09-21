#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
	bool isAnagram (string& s1, int l1, int r1, string& s2, int l2, int r2) {
		unordered_map<char, int> dict1;
		unordered_map<char, int> dict2;
		for (int i = l1; i < r1; i++) {
			char c = s1[i];
			auto found = dict1.find(c);
			if (found != dict1.end()) dict1[c]++;
			else dict1.insert({c, 1});
		}
		for (int i = l2; i < r2; i++) {
			char c = s2[i];
			auto found = dict2.find(c);
			if (found != dict2.end()) dict2[c]++;
			else dict2.insert({c, 1});
		}
		return dict1 == dict2;
	}

	bool helper (string& s1, int l1, int r1, string& s2, int l2, int r2) {
		if (r1 <= l1 || r2 <= l2 || r1 - l1 != r2 - l2) return false;

		bool same = true;
		for (int i = 0; i < r1 - l1; i++) if (s1[l1 + i] != s2[l2 + i]) { same = false; break; }
		if (same) return true;
		if (!isAnagram(s1, l1, r1, s2, l2, r2)) return false;
		for (int i = l1; i < r1; i++) {
			bool res1 = helper(s1, l1, i, s2, l2, l2 + (i - l1)) && helper(s1, i, r1, s2, r2 - (r1 - i), r2);
			if (res1) return true;
			bool res2 = helper(s1, l1, i, s2, r2 - (i - l1), r2) && helper(s1, i, r1, s2, l2, l2 + (r1 - i));
			if (res2) return true;
		}
		return false;
	}

    bool isScramble(string s1, string s2) {
		return helper(s1, 0, s1.length(), s2, 0, s2.length());
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1("abb");
	string s2("bab");
	Solution s;
	cout << s.isScramble(s1, s2) << endl;
	return 0;
}
