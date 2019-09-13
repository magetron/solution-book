#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	string format (vector<string>& strs, int width) {
		string s;
		int word_tot = 0;
		for (auto str : strs) word_tot += str.length();
		int tot_space = width - word_tot;
		int len_gap = (strs.size() > 1) ? tot_space / (strs.size() - 1) : tot_space;
		int more = (strs.size() > 1) ? tot_space % (strs.size() - 1) : 0;
		for (int i = 0; i < strs.size(); i++) {
			s += strs[i];
			if (i != strs.size() - 1) {
				for (int k = 0; k < len_gap; k++) s += ' ';
				if (more > 0) { s += ' '; more--; }
			}
		}
		if (strs.size() == 1) for (int k = 0; k < len_gap; k++) s += ' ';
		//cout << s << endl;
		return s;
	}

	string left_format (vector<string>& strs, int width) {
		string s;
		int len = 0;
		for (auto str : strs) {
			s += str;
			len += str.length();
			if (len < width) {
				s += ' ';
				len++;
			}
		}
		for (int k = 0; k < width - len; k++) s += ' ';
		return s;
	}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int i = 0;
		int cur_width = 0;
		vector<string> strs;
		vector<string> ans;
		while (i < words.size()) {
			cur_width += words[i].length() + 1;
			//cout << i << " " << cur_width << endl;
			if (cur_width <= maxWidth + 1) {
				strs.push_back(words[i]);
				i++;
			} else {
				ans.push_back(format(strs, maxWidth));
				strs.clear();
				cur_width = 0;
			}
		}
		ans.push_back(left_format(strs, maxWidth));
		return ans;
    }
};
	

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<string> words{"What", "must", "be", "acknowledgment", "shall", "be"};
	vector<string> words1{"This", "is", "an", "example", "of", "text", "justification."};
	vector<string> words2{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
	auto ans = s.fullJustify(words2, 20);
	for (auto s : ans) cout << s << endl;
	return 0;
}
