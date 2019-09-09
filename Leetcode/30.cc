#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			if (words.size() == 0) return vector<int>();
			set<int> ans;
			unordered_map<string, int> dict;
			for (auto it = words.begin(); it != words.end(); it++) {
				auto found = dict.find(*it);
				if (found == dict.end()) dict.insert({*it, 1});
				else (*found).second++;
			}
			unordered_map<string, int> recover_dict = dict;
			int i = 0;
			int j = 0;
			int interval = words[0].length();
			int count = 0;
			int ret_count = 0;
			bool needs_erase = false;
			while (i < s.length() - interval + 1 && j <= i) {
				string next_word = s.substr(i, interval);
				auto found = dict.find(next_word);
				if (found != dict.end() && found -> second > 0) {
					found -> second--;
					i += interval;
					count++;
					ret_count++;
					needs_erase = true;
				} else if (found != dict.end()) {
					string last_word = s.substr(j, interval);
					j += interval;
					auto f = dict.find(last_word);
					(*f).second++;
					count--;
				} else {
					i = i - interval * ret_count + 1;
					j = i;
					if (needs_erase) {
						dict = recover_dict;
						count = 0;
						ret_count = 0;
						needs_erase = false;
					}
				}
				if (count == words.size()) {
					ans.insert(j);
					i = i - interval * ret_count + 1;
					j = i;
					if (needs_erase) {
						dict = recover_dict;
						count = 0;
						ret_count = 0;
						needs_erase = false;
					}
				}
			}
			return vector<int>(ans.begin(), ans.end());
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	string str("barfoofoobarthefoobarman");
	vector<string> words{"bar","foo", "the"};
	vector<int> ans = s.findSubstring(str, words);
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}

