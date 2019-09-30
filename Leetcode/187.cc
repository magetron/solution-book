#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> dict;
		unordered_set<int> ans;
		int i = 0;
		while (i < s.length() - 10) {
			int j = i + 10;
			int h = 0;
			for (int k = i; k < j; k++) {
				int pos = -1;
				if 		(s[k] == 'A') pos = 0;
				else if (s[k] == 'C') pos = 1;
				else if (s[k] == 'G') pos = 2;
				else if (s[k] == 'T') pos = 3;
				h += pos << 2 * (k - i);
			}
			if (dict.find(h) != dict.end()) ans.insert(h);
			else dict.insert(h);
		}
		vector<string> ret;
		for (int a : ans) {
			string s;
			int count = 10;
			while (count) {
				int pos = a % 4;
				char c = '@';
				if 		(pos == 0) c = 'A';
				else if (pos == 1) c = 'C';
				else if (pos == 2) c = 'G';
				else if (pos == 3) c = 'T';
				s.push_back(c);
				a >>= 2;
				count--;	
			}
			ret.push_back(s);
		}
		return ret;
    }
};
