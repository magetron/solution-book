#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class WordDistance {
public:

	unordered_map<string, vector<int>> dict;
    
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) dict[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
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

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
