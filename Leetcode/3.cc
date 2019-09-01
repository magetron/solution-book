#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		set<char> dict;
		int len = s.length();
		int i = 0;
		int j = 0;
		int ans = 0;
		while (i < len - 1 && j < len) {
			auto f = dict.find(s[j]);
			if (f != dict.end()) dict.erase(s[i++]);
			else {
				dict.insert(j++);
				ans = max(ans, j - i);
			}
		}
		return ans;	
    }
};
