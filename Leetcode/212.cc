#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:

	struct Node {
		char c;
		vector<Node *> chs;
        bool end;
		string word;
		Node (char ch) : c(ch), end(false) { }
	};

	Node* root;

    void new_trie() {
		root = new Node('@');		
    }

    void insert(string word) {
		Node* r = root;
		for (auto c : word) {
			bool found = false;
			for (auto ch : r -> chs) if (ch -> c == c) {
				r = ch;
				found = true;
				break;
			}
			if (!found) {
				Node *new_ch = new Node(c);
				r -> chs.push_back(new_ch);
				r = new_ch;
			}
		}
        r -> end = true;
		r -> word = word;
    }

	vector<vector<int>> dir{{0,1}, {0, -1}, {1,0}, {-1, 0}};
	
	bool dfs (int i, int j, vector<vector<char>>& board, Node* root, vector<string>& ans) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
		if (root -> end) {
			bool ret = root -> chs.size() == 0;
			if (board[i][j] == root -> c) {
				ans.push_back(root -> word);
				root -> end = false;
				//cout << "pushing " << root -> word << endl;
				if (ret) {
					//cout << "deleting " << root -> c << endl;
					delete root;
					return true;
				}
			} else if (ret) return false;
		}
		if (root -> c == board[i][j]) {
			board[i][j] = '#';
			//cout << "on stack " << i << " " << j << " " << root -> c << endl;
			for (int k = 0; k < 4; k++)
				for (auto it = root -> chs.begin(); it != root -> chs.end(); it++) {
					bool res = dfs(i + dir[k][0], j + dir[k][1], board, *it, ans);
					if (res) {
						root -> chs.erase(it);
						it--;
					}
				}
			board[i][j] = root -> c;
			if (root -> chs.size() == 0) {
				//cout << "deleting " << root -> c << endl;
				delete root;
				return true;
			}
		} 
		return false;
	}

    
    void print_tree(Node* root) {
        for (auto ch : root -> chs) print_tree(ch);
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int m = board.size();
		if (!m) return {};
		int n = board[0].size();
		if (!n) return {};
		new_trie();
		for (string w : words) insert(w);
		vector<string> ans;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				for (auto it = root -> chs.begin(); it != root -> chs.end(); it++) if ((*it) -> c == board[i][j]) {
					//cout << "match at " << i << " " << j << " " << (*it) -> c << endl;
					bool res = dfs(i, j, board, *it, ans);
                    if (res) {
                        root -> chs.erase(it);
                        it--;
                    }
                    print_tree(root);
                    //cout << "root = " << root -> c << endl;
				}

		return ans;
    }
};

int main () {
	Solution s;
	vector<vector<char>>board {
		{'a', 'b'},
		{'a', 'a'}
	};
	vector<string> words {"aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba"};
	auto ans = s.findWords(board, words);
	for (auto s : ans) cout << s << endl;
	return 0;
}
