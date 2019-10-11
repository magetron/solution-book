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
		unordered_map<string, vector<int>> dict;
		for (int i = 0; i < words.size(); i++) dict[words[i]].push_back(i);
		auto s1 = dict[word1];
		auto s2 = dict[word2];
		int i = 0;
		int j = 0;
		int ans = INT_MAX;
		while (i < s1.size() && j < s2.size()) {
			ans = min(ans, abs(s2[j] - s1[i]));
			if (s2[j] < s1[i]) j++; else i++;
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

