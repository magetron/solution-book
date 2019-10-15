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
    bool canPermutePalindrome(string s) {
		unordered_set<char> dict;
		for (char c : s) {
			if (dict.find(c) == dict.end()) dict.insert(c); else dict.erase(c);
		}
		return dict.size() <= 1;
    }
};

	

