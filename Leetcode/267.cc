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

	inline void permute (string s, int l, vector<string>& ps) {
		if (l == s.length()) {
			ps.push_back(s);
			return;
		}
		for (int i = l; i < s.length(); i++) {
			int j = i - 1;
			while (j > l - 1 && s[j] != s[i]) j--;
			if (j != l - 1) continue;
			swap(s[i], s[l]);
			permute(s, l + 1, ps);
			swap(s[i], s[l]);
		}
	}

    vector<string> generatePalindromes(string s) {
		unordered_map<char, int> dict;
		for (char ch : s) {
			if (dict.find(ch) == dict.end()) {
				dict.insert({ch, 1});
			} else dict[ch]++;
		}
		string rep = "";
		string odd = "";
		for (auto p : dict) {
			if (p.second & 1) {
				if (odd.length() != 0) return {};
				for (int i = 0; i < p.second >> 1; i++) rep.push_back(p.first);
				odd.push_back(p.first);
			} else {
				for (int i = 0; i < p.second >> 1; i++) rep.push_back(p.first);
			}
		}
		vector<string> ps;
		permute(rep, 0, ps);
		//for (auto p : ps) cout << p << endl;
   		vector<string> ans(ps.size());
		for (int i = 0; i < ps.size(); i++) {
			string cpy = ps[i];
			reverse(cpy.begin(), cpy.end());
			ans[i] = ps[i] + odd + cpy;
		}
		return ans;
	}
};
