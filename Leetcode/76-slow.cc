#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:

		bool mapcmp(unordered_map<char, int>&dict, unordered_map<char, int>& std_dict) {
			for (auto pair : dict) if (std_dict[pair.first] > pair.second) return false;
			return true;
		}

		string minWindow (string s, string t) {
			unordered_map<char, int> dict;
			unordered_map<char, int> std_dict;
			
			for (int i = 0; i < t.length(); i++) {
				auto found = std_dict.find(t[i]);
				if (found != std_dict.end()) std_dict[t[i]]++;
				else std_dict.insert({t[i], 1});
			}

			for (auto pair : std_dict) dict.insert({pair.first, 0});

			int i = 0;
			int j = 0;
			int ans_len = INT_MAX;
			string ans = "";
			while (i <= j && j < s.length()) {
				auto found = dict.find(s[j]);
				if (found == dict.end()) { j++; continue; }
				else dict[s[j]]++;
				
				bool found_str = false;
				while (mapcmp(dict, std_dict)) {
					found_str = true;
					auto found = dict.find(s[i]);
					if (found == dict.end()) { i++; continue; }
					dict[s[i]]--;
					i++;
				}
				
				if (found_str) {
					i--;
					if (ans_len > j - i + 1) {
						ans_len = j - i + 1;
						ans = s.substr(i, ans_len);
						//cout << ans << " <-- ans " << endl;
					}
					i++;
				}
				/*
				cout << s.substr(i, j - i + 1) << " ";
				for (auto pair : dict) cout << pair.first << " " << pair.second << " ";
				cout << endl;
				*/

				j++;				

			}	

			return ans;
		}
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s("ADOBE");
	string t("ABC");

	Solution sol;
	cout << sol.minWindow(s, t) << endl;

	return 0;
}

