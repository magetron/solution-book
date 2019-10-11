#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
		int l1 = -1, l2 = -1;
		if (word1 != word2) {
			for (int i = 0; i < words.size(); i++) {
				if (words[i] == word1) l1 = i;
				else if (words[i] == word2) l2 = i;
				if (l1 != -1 && l2 != -1) ans = min(ans, abs(l2 - l1));
			}
		} else {
			for (int i = 0; i < words.size(); i++) {
				if (words[i] == word1) {
					l2 = l1;
					l1 = i;
				}
				if (l1 != -1 && l2 != -1) ans = min(ans, abs(l1 - l2));
			}
		}
		return ans;
    }
};
