#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int l;
		int r;
		Node (int ll, int rr) : l(ll), r(rr) { 
		}
};

class Solution {
public:
    string longestPalindrome(string s) {
		if (s.length() == 0) return "";
		if (s.length() == 1) return s;
        vector<Node> dict;
		for (int i = 0; i < s.length() - 1; i++) {
			if (i > 0 && s.at(i - 1) == s.at(i + 1))
				dict.push_back(Node(i - 1, i + 1));
			if (s.at(i) == s.at(i + 1))
				dict.push_back(Node(i, i + 1));
		}
		if (dict.size() == 0) return string(1, s.at(0));
		int max = 0;
		int max_l;
		for (auto it = dict.begin(); it != dict.end(); it++) {
			Node n = *it;
			while (n.l >= 0 && n.r < s.length() && s.at(n.l) == s.at(n.r)) { 
				n.l--; n.r++; 
			}
			int len = (n.r - 1) - (n.l + 1) + 1;
			if (len > max) {
				max = len;
				max_l = (n.l + 1);
			}
		}
		return s.substr(max_l, max);
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s("");
	Solution sol;
	cout << sol.longestPalindrome(s);

	return 0;
}
