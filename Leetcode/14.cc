#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		for (auto it = strs.begin(); it != strs.end(); it++) {
			if (it - strs.begin() == 0) {
				ans = *it;
				continue;
			}
			int i = 0;
			int j = 0;
			string str = *it;
			while (i < ans.length() && j < str.length()) 
				if (ans.at(i) == str.at(j)) { i++; j++; }
				else {
					ans = ans.substr(0, i);
					break;
				}
			ans = ans.substr(0, i);
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> strs;
	strs.push_back("aa");
	strs.push_back("a");
	strs.push_back("a");
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
