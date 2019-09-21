#include <bits/stdc++.h>

using namespace std;

struct node {
	string word;
	int count;
	node (string w, int c) : word(w), count(c) { }
};

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<node> q;
		q.push(node(beginWord, 1));
		vector<bool> visited(wordList.size(), false);
		while (!q.empty() && q.front().word != endWord) {
			node cur = q.front();
			//cout << cur.word << " " << cur.count << endl;
			//cout << q.size() << endl;
			q.pop();
			for (int i = 0; i < wordList.size(); i++) if (!visited[i]) {
				int diff = 0;
				for (int j = 0; j < cur.word.length(); j++) {
					if (cur.word[j] != wordList[i][j]) diff++;
					if (diff >= 2) break;
				}
				if (diff == 1) {
					q.push(node(wordList[i], cur.count + 1));
					visited[i] = true;
				}
			}
		}
		return (!q.empty()) ? q.front().count : 0;
    }
};

int main () {
	Solution s;
	vector<string> wl{"hot", "dot", "dog", "lot", "log"};
	cout << s.ladderLength("hit", "cog", wl) << endl;
	return 0;
}
