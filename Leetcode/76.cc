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
    string minWindow(string s, string t) {
  		vector<int> dict(128, 0);
		for (auto ch : t) dict[ch]++;
		int l = 0;
		int r = 0;
		int count = t.length();
		int ans_start = 0;
		int ans_len = INT_MAX;
		while (r < s.length()) {
			if (dict[s[r]] > 0) count--;
			dict[s[r]]--;
            r++;

			while (count == 0) {
                //cout << l << " " << r << endl;
				if (dict[s[l]] == 0) {
					if (r - l < ans_len) {
						ans_len = r - l;
						ans_start = l;
					}
					count++;
				}
				dict[s[l]]++;
				l++;
			}
		}
		
        //cout << ans_start << " " << ans_len << endl;
        
		return (ans_len == INT_MAX) ? "" : s.substr(ans_start, ans_len);
    }
};

