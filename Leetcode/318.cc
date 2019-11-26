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
    int maxProduct(vector<string>& words) {
		if (!words.size()) return 0;
		vector<unsigned int> hw;
		hw.reserve(words.size());
		for (string w : words) {
			unsigned int hash = 0;
			for (char c : w) {
				unsigned int offset = c - 97;
				if (((hash >> offset) & 1) == 0) hash += 1 << offset;
			}
			hw.emplace_back(hash);
		}
		//for (int h : hw) cout << h << " ";
		//cout << endl;
		int n = words.size();
		int ans = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++) if ((hw[i] & hw[j]) == 0) {
				ans = max(ans, (int)(words[i].length() * words[j].length()));
			}
		return ans;
    }
};

int main () {
	Solution s;
	vector<string> words{"a","ab","abc","d","cd","bcd","abcd"};
	cout << s.maxProduct(words) << endl;
	return 0;
}
