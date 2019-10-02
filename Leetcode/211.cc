#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class WordDictionary {
public:
	
	struct Node {
		char c;
		vector<Node*> chs;
		bool end = false;

		Node (char _c) : c(_c) { }
	};

	Node* root;

	WordDictionary() {
		root = new Node('@');
    }

    void addWord(string word) {
		Node* r = root;
		for (auto w : word) {
			bool found = false;
			for (auto ch : r -> chs) if (ch -> c == w) {
				found = true;
				r = ch;
				break;
			}
			if (!found) {
				Node* new_ch = new Node(w);
				r -> chs.push_back(new_ch);
				r = new_ch;
			}
		}
		r -> end = true;
    }

	bool helper(int pos, Node* root, string& word) {
		if (pos == word.length()) return true;
		if (word[pos] == '.') {
			for (auto ch : root -> chs) 
				if (helper(pos + 1, ch, word)) return true;
			return false;
		} else {
			for (auto ch : root -> chs) if (word[pos] == ch -> c) {
				if (helper(pos + 1, ch, word)) return true;
			}
			return false;
		}
	}		

    bool search(string word) {
		Node* r = root;
		return helper(0, root, word);
    }
};


