#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<string> letterCombinationsUtil(string digits) {
		vector<string> ans{""};
		while (digits.length() > 0) {
			vector<string> new_ans;
			switch (digits.at(0)) {
				case '0':
					for (auto it = ans.begin(); it != ans.end(); it++) *it += " ";
					break;
				case '2':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "a");
						new_ans.push_back(*it + "b");
						new_ans.push_back(*it + "c");
					}
					ans = new_ans;
					break;			
				case '3':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "d");
						new_ans.push_back(*it + "e");
						new_ans.push_back(*it + "f");
					}
					ans = new_ans;
					break;
				case '4':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "g");
						new_ans.push_back(*it + "h");
						new_ans.push_back(*it + "i");
					}
					ans = new_ans;
					break;
				case '5':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "j");
						new_ans.push_back(*it + "k");
						new_ans.push_back(*it + "l");
					}
					ans = new_ans;
					break;
				case '6':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "m");
						new_ans.push_back(*it + "n");
						new_ans.push_back(*it + "o");
					}
					ans = new_ans;
					break;
				case '7':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "p");
						new_ans.push_back(*it + "q");
						new_ans.push_back(*it + "r");
						new_ans.push_back(*it + "s");
					}
					ans = new_ans;
					break;
				case '8':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "t");
						new_ans.push_back(*it + "u");
						new_ans.push_back(*it + "v");
					}
					ans = new_ans;
					break;
				case '9':
					for (auto it = ans.begin(); it != ans.end(); it++) {
						new_ans.push_back(*it + "w");
						new_ans.push_back(*it + "x");
						new_ans.push_back(*it + "y");
						new_ans.push_back(*it + "z");
					}
					ans = new_ans;
					break;
			}
			digits = digits.substr(1, digits.length() - 1);
		}
		return ans;
    }


    vector<string> letterCombinations(string digits) {
		if (digits.length() == 0) return vector<string>();
		else return letterCombinationsUtil(digits);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	string str("2323");
	vector<string> strs = s.letterCombinations(str);
	for (auto it = strs.begin(); it != strs.end(); it++) cout << *it << endl;
	return 0;
}
