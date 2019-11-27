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

	void gen (string& word, vector<string>& ans, string& path, int pos, int left, bool abbr) {
		if (left == 0) {
			path += word.substr(pos, word.length() - pos);
			//cout << "left == 0 " << pos << " " <<  path << endl;
			ans.push_back(path);
			path.erase(path.end() - (word.length() - pos), path.end());
			//cout << path << endl;
			return;
		}
		if (word.length() - pos == left) {
			string leftstr = to_string(left);
			path += leftstr;
			ans.push_back(path);
			//cout << "word.length() - pos == left " << path << endl;
			path.erase(path.end() - leftstr.length(), path.end());
			//cout << path << endl;
			return;
		}
		if (abbr == false) {
			path.push_back(word[pos]);
			pos++;
			gen(word, ans, path, pos, left, true);
			path.pop_back();
			pos--;
		} else {
			for (int i = 0; i <= left; i++) {
				pos += i;
				if (i != 0) {
					string nstr = to_string(i);
					path += nstr;
					//cout << path << endl;
					gen(word, ans, path, pos, left - i, false);
					path.erase(path.end() - nstr.length(), path.end());
				} else {
					path.push_back(word[pos]);
					pos++;
					gen(word, ans, path, pos, left, true);
					path.pop_back();
					pos--;
				}
				pos -= i;
			}
		}
	}

    vector<string> generateAbbreviations(string word) {
		if (!word.length()) return {""};
		vector<string> ans;
		for (int i = 0; i <= word.length(); i++) {
			string path = "";
			gen(word, ans, path, 0, i, true);
		}
		return ans;
    }
};

int main () {
	Solution s;
	auto ans = s.generateAbbreviations("word");
	for (auto a : ans) cout << a << endl;
	return 0;
}
