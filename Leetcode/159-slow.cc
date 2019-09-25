#include <bits/stdc++.h>
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0;
		int j = 0;
		unordered_map<char, int> dict;
		int ans = 0;
		while (j < s.length()) {
			//cout << s.substr(i, j - i + 1) << endl;
			auto found = dict.find(s[j]);
			if (found == dict.end() && dict.size() <= 1) {
				dict.insert({s[j], 1});
				ans = max(ans, j - i + 1);
				j++;
			} else if (found != dict.end()) {
				dict[s[j]]++;
				ans = max(ans, j - i + 1);
				j++;
			} else {
				vector<int> count;
				vector<char> ch;
				for (auto p : dict) {
					ch.push_back(p.first);
					count.push_back(p.second);
				}
				//cout << ch[0] << " " << ch[1] << endl;
				//cout << count[0] << " " << count[1] << endl;
				while (count[0] != 0 && count[1] != 0) {
					if (s[i] == ch[0]) count[0]--; else count[1]--;
					i++;
				}
				//cout << ch[0] << " " << ch[1] << endl;
				//cout << count[0] << " " << count[1] << endl;
				if (count[0] == 0) {
					dict.erase(ch[0]);
					dict[ch[1]] = count[1];
				} else {
					dict.erase(ch[1]);
					dict[ch[0]] = count[0];
				}
			}
		}
		return ans;
    }
};

int main () {
	Solution s;
	cout << s.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;
	return 0;
}


