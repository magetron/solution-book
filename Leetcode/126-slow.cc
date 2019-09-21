#include <bits/stdc++.h>
#pragma GCC optimise ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	bool diff (string cur, string word) {
		int d = 0;
		for (int i = 0; i < cur.length(); i++) {
			if (cur[i] != word[i]) d++;
			if (d >= 2) break;
		}
		return d == 1;
	}


	void dfs (vector<string>& path, vector<vector<string>>& ans, string endWord, unordered_map<string, vector<string>>& next, unordered_map<string, int>& dist) {
		if (path.back() == endWord) {
			ans.push_back(path);
			return;
		}
		auto found = next.find(path.back());
		if (found == next.end()) return;
		for (auto n : next[path.back()]) {
			auto found = dist.find(n);
			if (found == dist.end()) continue;
			if (dist[n] == dist[path.back()] + 1) {
				path.push_back(n);
				dfs(path, ans, endWord, next, dist);
				path.pop_back();
			}
		}
	};

	vector<string> get_close (string cur, unordered_set<string>& wordList) {
		vector<string> close_list;
		for (int i = 0; i < cur.length(); i++)
			for (char j = 'a'; j <= 'z'; j++) if (j != cur[i]) {
				string new_str = cur.substr(0, i) + j + cur.substr(i + 1, cur.length() - i - 1);
				auto found = wordList.find(new_str);
				if (found != wordList.end()) close_list.push_back(new_str);
			}
		return close_list;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_set<string> wl(wordList.begin(), wordList.end());
		wl.erase(beginWord);
		unordered_map<string, vector<string>> next;
		unordered_map<string, int> dist;
		queue<pair<string, int>> q;
		q.push({beginWord, 0});
		while (!q.empty()) {
			string cur = q.front().first;
			//cout << cur << endl;
			int lvl = q.front().second;
			q.pop();
			vector<string> close_words = get_close(cur, wl);
			for (auto word : close_words) {
				//cout << cur << " " << word << endl;
				auto found = next.find(cur);
				if (found == next.end()) next.insert({cur, vector<string>{word}});
				else next[cur].push_back(word);
				auto found_dist = dist.find(word);
				if (found_dist == dist.end()) {
					dist.insert({word, lvl + 1});
					if (endWord != word) q.push({word, lvl + 1});
				}
			}
		}
		
		for (auto p : dist) cout << p.first << " " << p.second << endl;

		vector<string> path;
		vector<vector<string>> ans;
		path.push_back(beginWord);

		dfs(path, ans, endWord, next, dist);

		return ans;
	}


};

int main () {
	Solution s;
	vector<string> wl{"hot", "dot", "dog", "lot", "log", "cog"};
	//vector<string> wl{"a", "b", "c"};
	auto ans = s.findLadders("hit", "cog", wl);
	for (auto as : ans) {
		for (auto a : as) cout << a << " ";
		cout << endl;
	}
	return 0;
}
