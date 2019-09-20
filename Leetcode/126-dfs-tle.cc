#include <bits/stdc++.h>

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
	
	void helper(vector<string>& path, string target, vector<string>& dict, vector<vector<string>>& ans, vector<bool>& visited) {
		if (path.back() == target) {
			if (ans.size() > 0 && path.size() < ans[0].size()) ans.clear();
			if (ans.size() == 0 || path.size() == ans[0].size()) ans.push_back(path);
			return;
		}
		if (ans.size() > 0 && path.size() >= ans[0].size()) return;
		string cur = path.back();
		for (int i = 0; i < dict.size(); i++) if (!visited[i]) {
			int diff = 0;
			for (int j = 0; j < cur.size(); j++) {
				if (dict[i][j] != cur[j]) diff++;
				if (diff >= 2) break;
			}
			//cout << cur << " " << dict[i] << " " << diff << endl;
			if (diff == 1) {
				path.push_back(dict[i]);
				visited[i] = true;
				helper(path, target, dict, ans, visited);
				visited[i] = false;
				path.pop_back();
			}
		}
	}


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
     	vector<vector<string>> ans;
		vector<bool> visited(wordList.size(), false);
		vector<string> path(1, beginWord);
		helper(path, endWord, wordList, ans, visited);
		return ans;
    }
};

int main () {
	Solution s;
	vector<string> dict {"hot", "dot", "dog", "lot", "log", "cog"};
	auto ans = s.findLadders("hit", "cog", dict);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}
