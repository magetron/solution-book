#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
	vector<int> eval(int lp, int rp, string& s, unordered_map<pair<int, int>, vector<int>, hash_pair>& dict) {
		if (dict.find({lp, rp}) != dict.end()) return dict[{lp, rp}];
		bool found = false;
		vector<int> ans;
		for (int i = lp; i <= rp; i++) {
			if (!isdigit(s[i])) {
				found = true;
				vector<int> l = eval(lp, i - 1, s, dict);
				vector<int> r = eval(i + 1, rp, s, dict);
				for (int li : l) 
					for (int ri : r) {
						switch (s[i]) {
							case '+':
								ans.push_back(li + ri);
								break;
							case '-':
								ans.push_back(li - ri);
								break;
							case '*':
								ans.push_back(li * ri);
								break;
						}
					}
			}
		}
		if (!found) {
			ans.push_back(stoi(s.substr(lp, rp - lp + 1)));
			dict[{lp, rp}] = ans;
			return ans;
		}
		else {
			dict[{lp, rp}] = ans;
			return ans;
		}
	}

    vector<int> diffWaysToCompute(string input) {
		unordered_map<pair<int, int>, vector<int>, hash_pair> dict;
		return eval(0, input.length() - 1, input, dict);
    }
};

int main () {
	Solution s;
	auto ans = s.diffWaysToCompute("1+2*3");
	for (auto i : ans) cout << i << " "; cout << endl;
	return 0;
}
