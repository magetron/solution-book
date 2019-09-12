#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

class Solution {
public:

	vector<int> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 87, 89, 97};

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		unordered_map<ll, vector<string>> dict;
		for (int k = 0; k < strs.size(); k++) {
			ll hash = 1;
			for (auto ch : strs[k]) hash *= p[ch - 97];
			auto found = dict.find(hash);
			if (found != dict.end()) dict[hash].push_back(strs[k]);
			else dict.insert({hash, vector<string>(1, strs[k])});
		}
		for (auto pair : dict) ans.push_back(pair.second);
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

