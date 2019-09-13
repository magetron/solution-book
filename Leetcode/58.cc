#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		int word_end = -1;
  		for (int i = s.length() - 1; i >= 0; i--) 
			if (word_end == -1 && s.at(i) >= 'A' && s.at(i) <= 'z') word_end = i;
			else if (word_end != -1 && s.at(i) == ' ') return word_end - i;
		if (word_end == -1) return 0;
		else return word_end + 1;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str("");
	Solution s;
	cout << s.lengthOfLastWord(str) << endl;
	return 0;
}


