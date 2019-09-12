#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	map<char, int> std_counter;

	Solution () {
		for (int i = 0; i < 26; i++) std_counter.insert({i + 97, 0});
	};

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		sort(strs.begin(), strs.end(), [](const string &l, const string &r) { return l.size() < r.size(); } );
		//for (auto str : strs) cout << str << " ";
		//cout << endl;
		int i = 0;
		while (i < strs.size()) {
			int j = i + 1;
			while (j < strs.size() && strs[j].length() == strs[i].length()) j++;
			map<map<char, int>, vector<string>> dict;
			for (int k = i; k < j; k++) {
				auto counter = std_counter;
				for (auto ch : strs[k]) counter[ch]++;
				auto found = dict.find(counter);
				if (found != dict.end()) dict[counter].push_back(strs[k]);
				else dict.insert({counter, vector<string>(1, strs[k])});
			}
			for (auto pair : dict) ans.push_back(pair.second);
			i = j;
		}
		return ans;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;
	auto ans = s.groupAnagrams(strs);
	for (auto as : ans) {
		for (auto s : as) cout << s << " ";
		cout << endl;
	}
	return 0;
}

