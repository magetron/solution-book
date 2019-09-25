#include <bits/stdc++.h>
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0;
		int j = 0;
		char ch1 = '@', ch2 = '@';
		int count1 = 0, count2 = 0;
		int ans = 0;
		while (j < s.length()) {
			//cout << s.substr(i, j - i + 1) << endl;
			if (s[j] != ch1 && s[j] != ch2 && ch2 == '@') {
				if (ch1 == '@') {
					ch1 = s[j]; 
					count1 = 1;
				} else {
					ch2 = s[j];
					count2 = 1;
				}
				ans = max(ans, j - i + 1);
				j++;
			} else if (s[j] == ch1 || s[j] == ch2) {
				if (s[j] == ch1) count1++;
				else count2++;
				ans = max(ans, j - i + 1);
				j++;
			} else {
				//cout << ch[0] << " " << ch[1] << endl;
				//cout << count[0] << " " << count[1] << endl;
				while (count1 != 0 && count2 != 0) {
					if (s[i] == ch1) count1--; else count2--;
					i++;
				}
				//cout << ch[0] << " " << ch[1] << endl;
				//cout << count[0] << " " << count[1] << endl;
				if (count1 == 0) {
					ch1 = ch2;
					ch2 = '@';
					count1 = count2;
					count2 = 0;
				} else {
					ch2 = '@';	
				}
			}
		}
		return ans;
    }
};

int main () {
	Solution s;
	cout << s.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;
	return 0;
}


