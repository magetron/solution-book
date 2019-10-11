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
    int shortestDistance(vector<string>& words, string word1, string word2) {
    	int ans = INT_MAX;
		int l1 = -1, l2 = -1;
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == word1) l1 = i;
			else if (words[i] == word2) l2 = i;
			if (l1 != -1 && l2 != -1) ans = min(ans, abs(l2 - l1));
		}
		return ans;
	}
};

int main () {
	vector<string> ws{"apple", "google", "facebook", "coding", "google", "coding"};
	string w1 = "google";
	string w2 = "facebook";
	Solution s;
	cout << s.shortestDistance(ws, w1, w2) << endl;
	return 0;
}

