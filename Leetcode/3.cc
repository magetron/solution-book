#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_set <char> dict;
		int i = 0;
		int j = 0;
		int max = 0;
		while (i <= j && j < s.length()) {
			//cout << i << " " << j << endl;
			auto found = dict.find(s.at(j));
			if (found == dict.end()) 
				dict.insert(s.at(j++));
			else 
				dict.erase(s.at(i++));
			if (j - i > max) max = j - i;
		}
		return max;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s("abcabcbb");
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s);
	return 0;
}
